#include <HX711.h>

#define FL_CAL   26484  // 새 보정값 (kg/count)
#define FL_DOUT  2
#define FL_CLK   3

#define RL_CAL   26484  // 나중에 업데이트할 보정값 (kg/count)
#define RL_DOUT  4
#define RL_CLK   5

#define FR_CAL   26484  // 나중에 업데이트할 보정값 (kg/count)
#define FR_DOUT  6
#define FR_CLK   7

#define RR_CAL   26484  // 나중에 업데이트할 보정값 (kg/count)
#define RR_DOUT  8
#define RR_CLK   9

HX711 FL;
HX711 RL;
HX711 FR;
HX711 RR;

void setup() {
  Serial.begin(9600);

  FL.begin(FL_DOUT, FL_CLK);
  RL.begin(RL_DOUT, RL_CLK);
  FR.begin(FR_DOUT, FR_CLK);
  RR.begin(RR_DOUT, RR_CLK);

  // 초기 칼리브레이션 값 설정 (새 보정값 적용)
  FL.set_scale(FL_CAL);
  RL.set_scale(RL_CAL);
  FR.set_scale(FR_CAL);
  RR.set_scale(RR_CAL);
  
  FL.tare();
  RL.tare();
  FR.tare();
  RR.tare();
  
  Serial.println("로드셀 칼리브레이션을 시작합니다.");
}

void loop() {
  // 각 로드셀의 절댓값을 가져옴
  float fl_weight = abs(FL.get_units());
  float rl_weight = abs(RL.get_units());
  float fr_weight = abs(FR.get_units());
  float rr_weight = abs(RR.get_units());

  // 전체 추정 무게 계산 (FL 무게 + RL, FR, RR 무게)
  float estimated_total_weight = fl_weight + rl_weight + fr_weight + rr_weight;

  // 각 로드셀의 값 출력
  Serial.print("#FL RAW: ");
  Serial.print(fl_weight, 1);
  Serial.print("| RL RAW: ");
  Serial.print(rl_weight, 1);
  Serial.print("| FR RAW: ");
  Serial.print(fr_weight, 1);
  Serial.print("| RR RAW: ");
  Serial.println(rr_weight, 1);
  
  // 전체 추정 무게 출력
  Serial.print("Estimated Total Weight (based on FL): ");
  Serial.println(estimated_total_weight, 1);
  
  delay(1000);  // 1초마다 값 출력
}
