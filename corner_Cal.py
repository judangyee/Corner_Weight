FR = int(input("Front Right(kg): "))
FL = int(input("Front Left(kg): "))
RR = int(input("Rear Right(kg): "))
RL = int(input("Rear left(kg): "))
Axle_distance = int(input("Axle Distance(m): ")) #축간 거리
Track_width = int(input("Track Width(m): ")) #트랙폭
height = int(input("Height: ")) #뒷바퀴를 얼마나 높였는지
C_FR = int(input("Change FR(kg): "))
C_FL = int(input("Change FL(kg): "))
C_RR = int(input("Change RR(kg): "))
C_RL = int(input("Change RL(kg): "))

FC = abs((FR+FL)-(C_FL+C_FR)) #앞 바퀴 변화량
BC = abs((RR+RL)-(C_RL+C_RR)) #뒷 바퀴 변화량

length = 1.8 #차량 길이
bottom_length = (length**2 - height**2)**(1/2) #피타고라스로 밑변 계산

weight = FR+FL+RR+RL

# 앞뒤 무게 비
weight_Ratio = (FR+FL)/(RR+RL)

#양옆 무게비
rl_WR = (FR+RR)/(FL+RL)

#앞뒤 무게 중심
COGI = ((RR+RL)*Axle_distance)/weight

#좌우 무게 중심
COGL = ((FR+RR)*Track_width)/weight - Track_width/2

#높이 무게 중심
COGH = Axle_distance*(FC+BC)/weight*(height/bottom_length)

print("총 무게: ", weight)
print("앞뒤 무게비: ", weight_Ratio)
print("양옆 무게비: ", rl_WR)
print("앞뒤 무게 중심: ", COGI)
print("좌우 무게 중심: ", COGL)
print("높이 무게 중심: ", COGH)
