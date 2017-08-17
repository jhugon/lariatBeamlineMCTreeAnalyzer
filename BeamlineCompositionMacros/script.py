import os
for n in range(0,25):
  command="hadd -f -k /lariat/data/users/gpulliam/MCdata/64GeV_pos100A/Round"+str(n)+".root"
  print command
  for i in range(400*n,(n+1)*400):
    filename="/pnfs/lariat/scratch/users/gpulliam/MCdata/64GeV100A/MergedAtStartLinesim_LAriaT_13degProdxn_10degAna_SurveyedGeom_10000jobsof35k_64GeV_pos100Amps"+str(i)+".root"
    if os.path.isfile(filename):
      command= command+" "+filename
    else:
      print "File Missing: "+filename
  print "command made"  
  os.system(command)
