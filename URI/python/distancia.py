differential = int(input())
speed_veh_x = 60    #KM/H
speed_veh_y = 90    #KM/H
differential_time = int((differential/(speed_veh_y-speed_veh_x))*60)
print("{} minutos".format(differential_time))