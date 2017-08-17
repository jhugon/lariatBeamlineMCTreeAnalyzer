#!/usr/bin/env python

import ROOT as root
from helpers import *
root.gROOT.SetBatch(True)

if __name__ == "__main__":

  highYieldTracks = "*(TrackPresentDet1 && TrackPresentDet4 && PDGidDet4 != 22  && (TrackPresentDet2 || TrackPresentDet3))" # 3 point tracks
  pickyTracks = "*(TrackPresentDet1 && TrackPresentDet2 && TrackPresentDet3 && TrackPresentDet4 && PDGidDet4 != 22)" # 4 point tracks
  goodTOF = "*(TrackPresentTOFus && TrackPresentTOFds)"
  notPiPEMuK = "*(PDGidDet4!=211 && PDGidDet4!=2212 && PDGidDet4!=-11 && PDGidDet4!=-13 && PDGidDet4!=321)",

  cuts = ""

  #weightStr = "pzWeight"+cuts
  weightStr = "1"+cuts
  nData = 30860.0
  logy = True

  c = root.TCanvas()
  NMAX=10000000000
  #NMAX=100
  fileConfigs = [
    {
      'fn': "64GeV_pos100A_all.root",
      #'addFriend': ["friend", "friendTree_pip_v5.root"],
      #'fn': "test_pip_piAbsSelector.root",
      'name': "64GeV_pos100A",
      'title': "Beamline MC: 100 A, 64 GeV",
      'caption': "Beamline MC: 100 A, 64 GeV",
    },
  ]

  histConfigs = [
    {
      'name': "p_WC4",
      'xtitle': "p at WC4 [MeV/c]",
      'ytitle': "Particles / bin",
      'binning': [200,0,2000],
      'var': "sqrt(PxDet4*PxDet4+PyDet4*PyDet4+PzDet4*PzDet4)",
      'cuts': weightStr,
      #'normalize': True,
      'logy': logy,
    },
    {
      'name': "pz_WC4",
      'xtitle': "p_{z} at WC4 [MeV/c]",
      'ytitle': "Particles / bin",
      'binning': [200,0,2000],
      'var': "PzDet4",
      'cuts': weightStr,
      #'normalize': True,
      'logy': logy,
    },
  ]
  plotOneHistOnePlot(fileConfigs,histConfigs,c,"EventTree_Spill1",nMax=NMAX)

  histConfigs = [
    {
      'title': "No Cuts ~ High Yield Tracks",
      'xtitle': "True p_{z} at WC4 [MeV/c]",
      'ytitle': "Particles / bin",
      'binning': [200,0,2000],
      'var': "PzDet4",
      'cuts': "1",
      #'normalize': True,
      'logy': logy,
    },
    {
      'title': "High Yield Tracks",
      'xtitle': "True p_{z} at WC4 [MeV/c]",
      'ytitle': "Particles / bin",
      'binning': [200,0,2000],
      'var': "PzDet4",
      'cuts': "1"+highYieldTracks,
      #'normalize': True,
      'logy': logy,
    },
    {
      'title': "Picky Tracks",
      'xtitle': "True p_{z} at WC4 [MeV/c]",
      'ytitle': "Particles / bin",
      'binning': [200,0,2000],
      'var': "PzDet4",
      'cuts': "1"+pickyTracks,
      #'normalize': True,
      'logy': logy,
    },
    {
      'title': "Picky Tracks + ToF",
      'xtitle': "True p_{z} at WC4 [MeV/c]",
      'ytitle': "Particles / bin",
      'binning': [200,0,2000],
      'var': "PzDet4",
      'cuts': "1"+pickyTracks+goodTOF,
      #'normalize': True,
      'logy': logy,
    },
  ]
  for i in range(len(histConfigs)):
    histConfigs[i]["color"] = COLORLIST[i]
  plotManyHistsOnePlot(fileConfigs,histConfigs,c,"EventTree_Spill1",nMax=NMAX,outPrefix="BeamlineCuts_pz_")

  histConfigs = [
    {
      'captionright1':"Picky Tracks & ToF",
      'title': "#pi^{+}",
      'xtitle': "True p_{z} at WC4 [MeV/c]",
      'ytitle': "Particles / bin",
      'binning': [200,0,2000],
      'var': "PzDet4",
      'cuts': "1"+pickyTracks+goodTOF+"*(PDGidDet4==211)",
      #'normalize': True,
      'logy': logy,
      'stack':True,
    },
    {
      'title': "p",
      'xtitle': "True p_{z} at WC4 [MeV/c]",
      'ytitle': "Particles / bin",
      'binning': [200,0,2000],
      'var': "PzDet4",
      'cuts': "1"+pickyTracks+goodTOF+"*(PDGidDet4==2212)",
      #'normalize': True,
      'logy': logy,
      'stack':True,
    },
    {
      'title': "e^{+}",
      'xtitle': "True p_{z} at WC4 [MeV/c]",
      'ytitle': "Particles / bin",
      'binning': [200,0,2000],
      'var': "PzDet4",
      'cuts': "1"+pickyTracks+goodTOF+"*(PDGidDet4==-11)",
      #'normalize': True,
      'logy': logy,
      'stack':True,
    },
    {
      'title': "#mu^{+}",
      'xtitle': "True p_{z} at WC4 [MeV/c]",
      'ytitle': "Particles / bin",
      'binning': [200,0,2000],
      'var': "PzDet4",
      'cuts': "1"+pickyTracks+goodTOF+"*(PDGidDet4==-13)",
      #'normalize': True,
      'logy': logy,
      'stack':True,
    },
    {
      'title': "K^{+}",
      'xtitle': "True p_{z} at WC4 [MeV/c]",
      'ytitle': "Particles / bin",
      'binning': [200,0,2000],
      'var': "PzDet4",
      'cuts': "1"+pickyTracks+goodTOF+"*(PDGidDet4==321)",
      #'normalize': True,
      'logy': logy,
      'stack':True,
    },
  ]
  for i in range(len(histConfigs)):
    histConfigs[i]["color"] = COLORLIST[i]
  plotManyHistsOnePlot(fileConfigs,histConfigs,c,"EventTree_Spill1",nMax=NMAX,outPrefix="BeamlineComp_pz_")
