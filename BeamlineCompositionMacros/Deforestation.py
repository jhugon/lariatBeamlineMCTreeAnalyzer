import os

for i in range(0,25):
  # Edit .h and .C
  command ="sed -i 's/RoundX/Round"+str(i)+"/g' TreeCutter.h"
  print command
  os.system(command)
  command ="sed -i 's/RoundX/Round"+str(i)+"/g' TreeCutter.C"
  print command
  os.system(command)
  # A mini-macro that runs TreeCutter without commands in ROOT
  executecommand="root -l RunTreeCutter.C"
  os.system(executecommand)
  #Edit back .h and .C for next rouns
  command ="sed -i 's/Round"+str(i)+"/RoundX/g' TreeCutter.h"
  print command
  os.system(command)
  command ="sed -i 's/Round"+str(i)+"/RoundX/g' TreeCutter.C"
  print command
  os.system(command)
  
