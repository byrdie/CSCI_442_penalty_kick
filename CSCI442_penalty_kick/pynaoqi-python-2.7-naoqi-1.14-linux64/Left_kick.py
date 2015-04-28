# Choregraphe simplified export in Python.
from naoqi import ALProxy

names = list()
times = list()
keys = list()

class Left_kick:

  names.append("HeadPitch")
  times.append([ 1.16000, 2.68000, 3.20000, 4.24000, 5.12000, 6.12000])
  keys.append([ 0.04363, 0.26180, 0.17453, -0.27925, -0.26180, -0.24241])

  names.append("HeadYaw")
  times.append([ 1.16000, 2.68000, 3.20000, 4.24000, 5.12000, 6.12000])
  keys.append([ 0.00464, -0.00149, 0.00311, -0.04905, -0.03371, -0.02459])

  names.append("RAnklePitch")
  times.append([ 1.04000, 1.76000, 2.56000, 4.12000, 5.00000, 6.00000])
  keys.append([ 0.03226, 0.01745, 0.01745, 0.03491, 0.03491, 0.11501])

  names.append("RAnkleRoll")
  times.append([ 1.04000, 1.76000, 2.56000, 4.12000, 5.00000, 6.00000])
  keys.append([ -0.33161, -0.36652, -0.36652, -0.36652, -0.34732, 0.08433])

  names.append("RElbowRoll")
  times.append([ 1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000])
  keys.append([ 0.74096, 1.03396, 1.36990, 1.02015, 0.70722, 0.37732])

  names.append("RElbowYaw")
  times.append([ 1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000])
  keys.append([ -1.15353, -0.95411, -0.90809, -1.23023, -1.55697, -1.14441])

  #names.append("RHand")
  #times.append([ 1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000])
  #keys.append([ 0.00317, 0.00328, 0.00329, 0.00317, 0.00325, 0.00187])

  names.append("RHipPitch")
  times.append([ 1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000])
  keys.append([ 0.23159, 0.10580, 0.12217, 0.08433, 0.09046, 0.19171, 0.21020])

  names.append("RHipRoll")
  times.append([ 1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000])
  keys.append([ 0.34366, 0.36820, 0.36820, 0.36513, 0.36667, 0.36513, -0.10129])

  names.append("RHipYawPitch")
  times.append([ 1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000])
  keys.append([ -0.18097, -0.25307, -0.06285, -0.05058, -0.18711, -0.24386, -0.31903])

  names.append("RKneePitch")
  times.append([ 1.04000, 1.76000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000])
  keys.append([ -0.08727, -0.08727, -0.09235, -0.07973, -0.07973, -0.07819, -0.07666, -0.09208])

  names.append("RShoulderPitch")
  times.append([ 1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000])
  keys.append([ 1.48649, 1.35917, 1.41746, 1.59847, 1.63835, 1.50021])

  names.append("RShoulderRoll")
  times.append([ 1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000])
  keys.append([ -0.02305, -0.01998, -0.13197, -0.11816, -0.02305, -0.03524])

  #names.append("RWristYaw")
  #times.append([ 1.08000, 2.60000, 3.12000, 4.16000, 5.04000, 6.04000])
  #keys.append([ 0.24435, 0.23935, 0.22094, 0.20253, 0.19026, -0.12736])

  names.append("LAnklePitch")
  times.append([ 1.04000, 1.32000, 1.76000, 2.24000, 2.56000, 2.84000, 3.08000, 3.36000, 3.68000, 4.12000, 5.00000, 6.00000])
  keys.append([ 0.08727, -0.08727, -0.59341, -0.40143, 0.12217, -0.05236, -0.12217, 0.24435, -0.12217, -0.64403, -0.21991, 0.11356])

  names.append("LAnkleRoll")
  times.append([ 1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000])
  keys.append([ -0.40143, -0.10887, -0.13802, -0.00000, -0.18097, -0.34558, -0.05066])

  names.append("LElbowRoll")
  times.append([ 1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000])
  keys.append([ -0.64117, -1.15353, -1.38056, -1.36062, -0.96024, -0.45564])

  names.append("LElbowYaw")
  times.append([ 1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000])
  keys.append([ 0.99714, 0.86368, 0.90970, 0.63205, 0.84834, 1.49714])

  #names.append("LHand")
  #times.append([ 1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000])
  #keys.append([ 0.00129, 0.00136, 0.00132, 0.00128, 0.00133, 0.00391])

  names.append("LHipPitch")
  times.append([ 1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000])
  keys.append([ 0.16265, -0.39726, -1.11876, -1.11978, -0.78540, -0.29142, 0.21318])

  names.append("LHipRoll")
  times.append([ 1.04000, 2.56000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000])
  keys.append([ 0.47124, 0.54001, 0.32218, 0.12276, 0.36360, 0.41713, 0.05825])

  names.append("LKneePitch")
  times.append([ 1.04000, 2.56000, 2.84000, 3.08000, 3.36000, 4.12000, 5.00000, 6.00000])
  keys.append([ -0.08901, 1.97575, 1.97222, 1.23918, 0.24435, 1.53589, 0.62430, -0.07666])

  names.append("LShoulderPitch")
  times.append([ 1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000])
  keys.append([ 1.52782, 1.46033, 1.47413, 1.24096, 1.51862, 1.54938])

  names.append("LShoulderRoll")
  times.append([ 1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000])
  keys.append([ 0.12268, 0.04138, 0.14569, 0.13955, 0.14722, 0.03993])

  #names.append("LWristYaw")
  #times.append([ 1.00000, 2.52000, 3.04000, 4.08000, 4.96000, 5.96000])
  #keys.append([ -0.08727, -0.07359, -0.05058, -0.06285, 0.05680, 0.00149])

  def __init__(self, motion):
    	self.motion = motion
	self.pose = pose

  def action(self):
    try:
      # uncomment the following line and modify the IP if you use this script outside Choregraphe.
	robotIp = "153.90.198.220"
	pose = ALRobotPostureProxy(robotIp, 9559);
	self.pose.goToPosture("Stand", 0.9);
      	motion = ALProxy("ALMotion", robotIp, 9559)
      	self.motion.angleInterpolation(names, keys, times, True);
    except BaseException, err:
      print err

