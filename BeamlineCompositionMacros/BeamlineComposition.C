#define BeamlineComposition_cxx
#include "BeamlineComposition.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <TFile.h>
#include <TH1.h>
#include "THStack.h" 
#include "TTree.h"
#include "TLegend.h"
#include <TH2.h>
#include "TF1.h"
#include "TFitResult.h"
#include "TMath.h"
void BeamlineComposition::Loop()
{
  double I=100; //MUST CHANGE THIS TO THE CURRENT USED FOR THE SAMPLE AND IS ALWAYS POSITIVE!
  double B=(-.1538*pow(10,-4)*pow(I,3)+.2245*pow(10,-2)*pow(I,2)-.1012*I+36.59)*I/10000;
 // Intialize some variables and histograms
  double dxds,dzds,dxus,dzus,thetaus,thetads,yup,ydown,dyds,dyus=0;
  double momentum=0;
  //Defining the midplane with a slope and intercept in form x=mz+b
  double b_mid=-31037;

  double m_mid=tan(TMath::DegToRad()*82); 
  TH1F* PionMom=new TH1F("PionMom","PionMom",200,0,2000);
  TH1F* MuonMom=new TH1F("MuonMom","MuonMom",200,0,2000);
  TH1F* ElecMom=new TH1F("ElecMom","ElecMom",200,0,2000);
  TH1F* ProtonMom=new TH1F("ProtonMom","ProtonMom",200,0,2000);
  TH1F* KaonMom=new TH1F("KaonMom","KaonMom",200,0,2000);
  TH2F* RecoComp= new TH2F("RecoComp", "Truth Vs Reconstruction", 500,0,2000,500,0,2000);
  TH1F* RecoDiff = new TH1F("Residual", "Percent Error of Reco",500,-1,1);
  THStack *h1= new THStack("h1","Beamline Composition by Particle and Momentum");
  THStack *h2 = new THStack("h2","Momentum Error by Particle");
  TH1F* PionError=new TH1F("PionError","PionError",1000,-1,1);
  TH1F* MuonError=new TH1F("MuonError","MuonError",1000,-1,1);
  TH1F* ElecError=new TH1F("ElecError","ElecError",1000,-1,1);
  TH1F* ProtonError=new TH1F("ProtonError","ProtonError",1000,-1,1);
  TH1F* KaonError=new TH1F("KaonError","KaonError",1000,-1,1);
  TH2F* YKink=new TH2F("Ykink","Ykink vs Momentum Error",1000,-1,1,200,-10,10);
  
  TH1F* PionMom_s2=new TH1F("PionMom_s2","PionMom_s2",200,0,2000);
  TH1F* MuonMom_s2=new TH1F("MuonMom_s2","MuonMom_s2",200,0,2000);
  TH1F* ElecMom_s2=new TH1F("ElecMom_s2","ElecMom_s2",200,0,2000);
  TH1F* ProtonMom_s2=new TH1F("ProtonMom_s2","ProtonMom_s2",200,0,2000);
  TH1F* KaonMom_s2=new TH1F("KaonMom_s2","KaonMom_s2",200,0,2000);
  TH2F* RecoComp_s2= new TH2F("RecoComp_s2", "Truth Vs Reconstruction_s2", 500,0,2000,500,0,2000);
  TH1F* RecoDiff_s2 = new TH1F("Residual_s2", "Percent Error of Reco_s2",1000,-1,1);
  TH1F* PionError_s2=new TH1F("PionError_s2","PionError_s2",1000,-1,1);
  TH1F* MuonError_s2=new TH1F("MuonError_s2","MuonError_s2",1000,-1,1);
  TH1F* ElecError_s2=new TH1F("ElecError_s2","ElecError_s2",1000,-1,1);
  TH1F* ProtonError_s2=new TH1F("ProtonError_s2","ProtonError_s2",1000,-1,1);
  TH1F* KaonError_s2=new TH1F("KaonError_s2","KaonError_s2",1000,-1,1);
  
  TH1F* PionMom_s3=new TH1F("PionMom_s3","PionMom_s3",200,0,2000);
  TH1F* MuonMom_s3=new TH1F("MuonMom_s3","MuonMom_s3",200,0,2000);
  TH1F* ElecMom_s3=new TH1F("ElecMom_s3","ElecMom_s3",200,0,2000);
  TH1F* ProtonMom_s3=new TH1F("ProtonMom_s3","ProtonMom_s3",200,0,2000);
  TH1F* KaonMom_s3=new TH1F("KaonMom_s3","KaonMom_s3",200,0,2000);
  TH2F* RecoComp_s3= new TH2F("RecoComp_s3", "Truth Vs Reconstruction_s3", 500,0,2000,500,0,2000);
  TH1F* RecoDiff_s3 = new TH1F("Residual_s3", "Percent Error of Reco_s3",1000,-1,1);
  TH1F* PionError_s3=new TH1F("PionError_s3","PionError_s3",1000,-1,1);
  TH1F* MuonError_s3=new TH1F("MuonError_s3","MuonError_s3",1000,-1,1);
  TH1F* ElecError_s3=new TH1F("ElecError_s3","ElecError_s3",1000,-1,1);
  TH1F* ProtonError_s3=new TH1F("ProtonError_s3","ProtonError_s3",1000,-1,1);
  TH1F* KaonError_s3=new TH1F("KaonError_s3","KaonError_s3",1000,-1,1);
  THStack *h_s2= new THStack("h_s2","Miss WC2: Beamline Composition by Particle and Momentum");
  THStack *h_s3= new THStack("h_s3","Miss WC3: Beamline Composition by Particle and Momentum");
  
  THStack *h_s2_e= new THStack("h_s2_e","Miss WC2: Momentum Error by Particle");
  THStack *h_s3_e= new THStack("h_s3_e","Miss WC3: Momentum Error by Particle");
  
  THStack *AllTrackStack= new THStack("HY Composition","HY Composition");
  TH1F* PionMom_all=new TH1F("PionMom_all","PionMom_all",200,0,2000);
  TH1F* MuonMom_all=new TH1F("MuonMom_all","MuonMom_all",200,0,2000);
  TH1F* ElecMom_all=new TH1F("ElecMom_all","ElecMom_all",200,0,2000);
  TH1F* ProtonMom_all=new TH1F("ProtonMom_all","ProtonMom_all",200,0,2000);
  TH1F* KaonMom_all=new TH1F("KaonMom_all","KaonMom_all",200,0,2000);
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   std::cout<<"Total entries: "<<nentries<<std::endl;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      if (jentry%10000==0){std::cout<<"Percentage done: "<<double(jentry)/(double)nentries*100<<std::endl;}
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      //Calculate the momentum for 4 point tracks and Fill relevant histograms
      if(TrackPresentDet1 && TrackPresentDet2 && TrackPresentDet3 && TrackPresentDet4 && PDGidDet4!=22 && TrackPresentTOFus && TrackPresentTOFds){
      dxds=xDet4-xDet3;
      dzds=zDet4-zDet3;      
      dxus=xDet2-xDet1;
      dzus=zDet2-zDet1;
      dyus=yDet2-yDet1;
      dyds=yDet4-yDet3;
      thetads=atan(dxds/dzds);
      thetaus=atan(dxus/dzus);
      yup=atan(dyus/dzus);
      ydown=atan(dyds/dzds);
      YKink->Fill((momentum-PzDet4)/(PzDet4),180/3.14159265359*(ydown-yup));
      momentum=B*1182/(3.3*(sin(thetads)-sin(thetaus)));
      if (PDGidDet4==-211){
        PionMom->Fill(momentum);
	PionMom_all->Fill(momentum);
	RecoComp->Fill(PzDet4,momentum);
	RecoDiff->Fill((momentum-PzDet4)/(PzDet4));
	PionError->Fill((momentum-PzDet4)/(PzDet4));
	
      }
      if (PDGidDet4==13){
        MuonMom->Fill(momentum);
	MuonMom_all->Fill(momentum);
	RecoComp->Fill(PzDet4,momentum);
	RecoDiff->Fill((momentum-PzDet4)/(PzDet4));
	MuonError->Fill((momentum-PzDet4)/(PzDet4));
      }
      if (PDGidDet4==11){
        ElecMom->Fill(momentum);
	ElecMom_all->Fill(momentum);
	RecoComp->Fill(PzDet4,momentum);
	RecoDiff->Fill((momentum-PzDet4)/(PzDet4));
	ElecError->Fill((momentum-PzDet4)/(PzDet4));
      }
      if (PDGidDet4==-321){
        KaonMom->Fill(momentum);
	KaonMom_all->Fill(momentum);
	RecoComp->Fill(PzDet4,momentum);
	RecoDiff->Fill((momentum-PzDet4)/(PzDet4));
	KaonError->Fill((momentum-PzDet4)/(PzDet4));
      }
      if (PDGidDet4==-2212){
        ProtonMom->Fill(momentum);
	ProtonMom_all->Fill(momentum);
	RecoComp->Fill(PzDet4,momentum);
	RecoDiff->Fill((momentum-PzDet4)/(PzDet4));
	ProtonError->Fill((momentum-PzDet4)/(PzDet4));
      }       
    }
    //3 Point tracks missing WC2
     if(TrackPresentDet1 && !TrackPresentDet2 && TrackPresentDet3 && TrackPresentDet4 && PDGidDet4!=22 && TrackPresentTOFus && TrackPresentTOFds){
    //Find the intersection of the line through the US WC hits with the line of the midplane-> z=(b_mid-b_us)/(m_us-m_mid)
      double m_ds=(xDet4-xDet3)/(zDet4-zDet3);
      double b_ds=xDet3-m_ds*zDet3;
      double z_miss=(b_mid-b_ds)/(m_ds-m_mid);
      double x_miss=m_ds*z_miss+b_ds;
    // Use the hit at the midplane as the point to use with WC4 hit to calculate the momentum.
      dxds=xDet4-xDet3;
      dzds=zDet4-zDet3;      
      dxus=x_miss-xDet1;
      dzus=z_miss-zDet1;
      
      thetads=atan(dxds/dzds);
      thetaus=atan(dxus/dzus);

      momentum=B*1182/(3.3*(sin(thetads)-sin(thetaus)));
      if (PDGidDet4==-211){
        PionMom_s2->Fill(momentum);
	PionMom_all->Fill(momentum);
	RecoComp_s2->Fill(PzDet4,momentum);
	RecoDiff_s2->Fill((momentum-PzDet4)/(PzDet4));
	PionError_s2->Fill((momentum-PzDet4)/(PzDet4));
	
      }
      if (PDGidDet4==13){
        MuonMom_s2->Fill(momentum);
	MuonMom_all->Fill(momentum);
	RecoComp_s2->Fill(PzDet4,momentum);
	RecoDiff_s2->Fill((momentum-PzDet4)/(PzDet4));
	MuonError_s2->Fill((momentum-PzDet4)/(PzDet4));
      }
      if (PDGidDet4==11){
        ElecMom_s2->Fill(momentum);
	ElecMom_all->Fill(momentum);
	RecoComp_s2->Fill(PzDet4,momentum);
	RecoDiff_s2->Fill((momentum-PzDet4)/(PzDet4));
	ElecError_s2->Fill((momentum-PzDet4)/(PzDet4));
      }
      if (PDGidDet4==-321){
        KaonMom_s2->Fill(momentum);
	KaonMom_all->Fill(momentum);
	RecoComp_s2->Fill(PzDet4,momentum);
	RecoDiff_s2->Fill((momentum-PzDet4)/(PzDet4));
	KaonError_s2->Fill((momentum-PzDet4)/(PzDet4));
      }
      if (PDGidDet4==-2212){
        ProtonMom_s2->Fill(momentum);
	ProtonMom_all->Fill(momentum);
	RecoComp_s2->Fill(PzDet4,momentum);
	RecoDiff_s2->Fill((momentum-PzDet4)/(PzDet4));
	ProtonError_s2->Fill((momentum-PzDet4)/(PzDet4));
      } 
    }
  //3 point tracks missing WC3
    if(TrackPresentDet1 && TrackPresentDet2 && !TrackPresentDet3 && TrackPresentDet4 && PDGidDet4!=22 && TrackPresentTOFus && TrackPresentTOFds){
    //Find the intersection of the line through the US WC hits with the line of the midplane-> z=(b_mid-b_us)/(m_us-m_mid)
      double m_us=(xDet2-xDet1)/(zDet2-zDet1);
      double b_us=xDet1-m_us*zDet1;
      double z_miss=(b_mid-b_us)/(m_us-m_mid);
      double x_miss=m_us*z_miss+b_us;
    // Use the hit at the midplane as the point to use with WC4 hit to calculate the momentum.
      dxds=xDet4-x_miss;
      dzds=zDet4-z_miss;      
      dxus=xDet2-xDet1;
      dzus=zDet2-zDet1;
      
      thetads=atan(dxds/dzds);
      thetaus=atan(dxus/dzus);

      momentum=B*1182/(3.3*(sin(thetads)-sin(thetaus)));
      if (PDGidDet4==-211){
        PionMom_s3->Fill(momentum);
	PionMom_all->Fill(momentum);
	RecoComp_s3->Fill(PzDet4,momentum);
	RecoDiff_s3->Fill((momentum-PzDet4)/(PzDet4));
	PionError_s3->Fill((momentum-PzDet4)/(PzDet4));
	
      }
      if (PDGidDet4==13){
        MuonMom_s3->Fill(momentum);
	MuonMom_all->Fill(momentum);
	RecoComp_s3->Fill(PzDet4,momentum);
	RecoDiff_s3->Fill((momentum-PzDet4)/(PzDet4));
	MuonError_s3->Fill((momentum-PzDet4)/(PzDet4));
      }
      if (PDGidDet4==11){
        ElecMom_s3->Fill(momentum);
	ElecMom_all->Fill(momentum);
	RecoComp_s3->Fill(PzDet4,momentum);
	RecoDiff_s3->Fill((momentum-PzDet4)/(PzDet4));
	ElecError_s3->Fill((momentum-PzDet4)/(PzDet4));
      }
      if (PDGidDet4==-321){
        KaonMom_s3->Fill(momentum);
	KaonMom_all->Fill(momentum);
	RecoComp_s3->Fill(PzDet4,momentum);
	RecoDiff_s3->Fill((momentum-PzDet4)/(PzDet4));
	KaonError_s3->Fill((momentum-PzDet4)/(PzDet4));
      }
      if (PDGidDet4==-2212){
        ProtonMom_s3->Fill(momentum);
	ProtonMom_all->Fill(momentum);
	RecoComp_s3->Fill(PzDet4,momentum);
	RecoDiff_s3->Fill((momentum-PzDet4)/(PzDet4));
	ProtonError_s3->Fill((momentum-PzDet4)/(PzDet4));
      } 
    }
  }
  PionMom->SetLineWidth(1);
  PionMom->SetLineColor(1);
  PionMom->SetFillColor(9);
  PionMom->SetName("PionMom");
  
  KaonMom->SetLineWidth(1);
  KaonMom->SetLineColor(1);
  KaonMom->SetFillColor(43);
  KaonMom->SetName("KaonMom");
  
  MuonMom->SetLineWidth(1);
  MuonMom->SetLineColor(1);
  MuonMom->SetFillColor(41);
  MuonMom->SetName("MuonMom");
  
  ElecMom->SetLineWidth(1);
  ElecMom->SetLineColor(1);
  ElecMom->SetFillColor(40);
  ElecMom->SetName("ElecMom");
  
  ProtonMom->SetLineWidth(1);
  ProtonMom->SetLineColor(1);
  ProtonMom->SetFillColor(2);
  ProtonMom->SetName("ProtonMom");
  
  PionMom_all->SetLineWidth(1);
  PionMom_all->SetLineColor(1);
  PionMom_all->SetFillColor(9);
  PionMom_all->SetName("PionMom_all");
  
  KaonMom_all->SetLineWidth(1);
  KaonMom_all->SetLineColor(1);
  KaonMom_all->SetFillColor(43);
  KaonMom_all->SetName("KaonMom_all");
  
  MuonMom_all->SetLineWidth(1);
  MuonMom_all->SetLineColor(1);
  MuonMom_all->SetFillColor(41);
  MuonMom_all->SetName("MuonMom_all");
  
  ElecMom_all->SetLineWidth(1);
  ElecMom_all->SetLineColor(1);
  ElecMom_all->SetFillColor(40);
  ElecMom_all->SetName("ElecMom_all");
  
  ProtonMom_all->SetLineWidth(1);
  ProtonMom_all->SetLineColor(1);
  ProtonMom_all->SetFillColor(2);
  ProtonMom_all->SetName("ProtonMom_all");
  
  PionError->SetLineWidth(1);
  PionError->SetLineColor(1);
  PionError->SetFillColor(9);
  PionError->SetName("PionError");
  
  KaonError->SetLineWidth(1);
  KaonError->SetLineColor(1);
  KaonError->SetFillColor(43);
  KaonError->SetName("KaonError");
  
  MuonError->SetLineWidth(1);
  MuonError->SetLineColor(1);
  MuonError->SetFillColor(41);
  MuonError->SetName("MuonError");
  
  ElecError->SetLineWidth(1);
  ElecError->SetLineColor(1);
  ElecError->SetFillColor(40);
  ElecError->SetName("ElecError");
  
  ProtonError->SetLineWidth(1);
  ProtonError->SetLineColor(1);
  ProtonError->SetFillColor(2);
  ProtonError->SetName("ProtonError");
  
  //Miss WC2 plot formatting
  PionMom_s2->SetLineWidth(1);
  PionMom_s2->SetLineColor(1);
  PionMom_s2->SetFillColor(9);
  PionMom_s2->SetName("PionMom_s2");
  
  KaonMom_s2->SetLineWidth(1);
  KaonMom_s2->SetLineColor(1);
  KaonMom_s2->SetFillColor(43);
  KaonMom_s2->SetName("KaonMom_s2");
  
  MuonMom_s2->SetLineWidth(1);
  MuonMom_s2->SetLineColor(1);
  MuonMom_s2->SetFillColor(41);
  MuonMom_s2->SetName("MuonMom_s2");
  
  ElecMom_s2->SetLineWidth(1);
  ElecMom_s2->SetLineColor(1);
  ElecMom_s2->SetFillColor(40);
  ElecMom_s2->SetName("ElecMom_s2");
  
  ProtonMom_s2->SetLineWidth(1);
  ProtonMom_s2->SetLineColor(1);
  ProtonMom_s2->SetFillColor(2);
  ProtonMom_s2->SetName("ProtonMom_s2");
  
  PionError_s2->SetLineWidth(1);
  PionError_s2->SetLineColor(1);
  PionError_s2->SetFillColor(9);
  PionError_s2->SetName("PionError_s2");
  
  KaonError_s2->SetLineWidth(1);
  KaonError_s2->SetLineColor(1);
  KaonError_s2->SetFillColor(43);
  KaonError_s2->SetName("KaonError_s2");
  
  MuonError_s2->SetLineWidth(1);
  MuonError_s2->SetLineColor(1);
  MuonError_s2->SetFillColor(41);
  MuonError_s2->SetName("MuonError_s2");
  
  ElecError_s2->SetLineWidth(1);
  ElecError_s2->SetLineColor(1);
  ElecError_s2->SetFillColor(40);
  ElecError_s2->SetName("ElecError_s2");
  
  ProtonError_s2->SetLineWidth(1);
  ProtonError_s2->SetLineColor(1);
  ProtonError_s2->SetFillColor(2);
  ProtonError_s2->SetName("ProtonError_s2");
  
  //Miss WC plot formatting
  PionMom_s3->SetLineWidth(1);
  PionMom_s3->SetLineColor(1);
  PionMom_s3->SetFillColor(9);
  PionMom_s3->SetName("PionMom_s3");
  
  KaonMom_s3->SetLineWidth(1);
  KaonMom_s3->SetLineColor(1);
  KaonMom_s3->SetFillColor(43);
  KaonMom_s3->SetName("KaonMom_s3");
  
  MuonMom_s3->SetLineWidth(1);
  MuonMom_s3->SetLineColor(1);
  MuonMom_s3->SetFillColor(41);
  MuonMom_s3->SetName("MuonMom_s3");
  
  ElecMom_s3->SetLineWidth(1);
  ElecMom_s3->SetLineColor(1);
  ElecMom_s3->SetFillColor(40);
  ElecMom_s3->SetName("ElecMom_s3");
  
  ProtonMom_s3->SetLineWidth(1);
  ProtonMom_s3->SetLineColor(1);
  ProtonMom_s3->SetFillColor(2);
  ProtonMom_s3->SetName("ProtonMom_s3");
  
  PionError_s3->SetLineWidth(1);
  PionError_s3->SetLineColor(1);
  PionError_s3->SetFillColor(9);
  PionError_s3->SetName("PionError_s3");
  
  KaonError_s3->SetLineWidth(1);
  KaonError_s3->SetLineColor(1);
  KaonError_s3->SetFillColor(43);
  KaonError_s3->SetName("KaonError_s3");
  
  MuonError_s3->SetLineWidth(1);
  MuonError_s3->SetLineColor(1);
  MuonError_s3->SetFillColor(41);
  MuonError_s3->SetName("MuonError_s3");
  
  ElecError_s3->SetLineWidth(1);
  ElecError_s3->SetLineColor(1);
  ElecError_s3->SetFillColor(40);
  ElecError_s3->SetName("ElecError_s3");
  
  ProtonError_s3->SetLineWidth(1);
  ProtonError_s3->SetLineColor(1);
  ProtonError_s3->SetFillColor(2);
  ProtonError_s3->SetName("ProtonError_s3");
  
  TFitResultPtr r1_s2=RecoDiff_s2->Fit("gaus","S","",-.2,.2);
  TFitResultPtr r2_s2=RecoDiff_s2->Fit("gaus","S","",-1,1);
  TF1 *DoubleGauss_s2 = new TF1("DoubleGauss_s2","gaus(0)+gaus(3)");
  DoubleGauss_s2->SetParameter(0,r1_s2->Parameter(0));
  DoubleGauss_s2->SetParameter(1,r1_s2->Parameter(1));
  DoubleGauss_s2->SetParameter(2,r1_s2->Parameter(2));
  DoubleGauss_s2->SetParameter(3,10);
  DoubleGauss_s2->SetParameter(4,r2_s2->Parameter(1));
  DoubleGauss_s2->SetParameter(5,r2_s2->Parameter(2));
  RecoDiff_s2->Fit(DoubleGauss_s2);
  
  
  TFitResultPtr r1=RecoDiff->Fit("gaus","S","",-.2,.2);
  TFitResultPtr r2=RecoDiff->Fit("gaus","S","",-1,1);
  TF1 *DoubleGauss = new TF1("DoubleGauss","gaus(0)+gaus(3)");
  DoubleGauss->SetParameter(0,r1->Parameter(0));
  DoubleGauss->SetParameter(1,r1->Parameter(1));
  DoubleGauss->SetParameter(2,r1->Parameter(2));
  DoubleGauss->SetParameter(3,10);
  DoubleGauss->SetParameter(4,r2->Parameter(1));
  DoubleGauss->SetParameter(5,r2->Parameter(2));
  DoubleGauss->SetParLimits(5,0,1);
  RecoDiff->Fit(DoubleGauss);
  
  TFitResultPtr r1_s3=RecoDiff_s3->Fit("gaus","S","",-.2,.2);
  TFitResultPtr r2_s3=RecoDiff_s3->Fit("gaus","S","",-1,1);
  TF1 *DoubleGauss_s3 = new TF1("DoubleGauss_s3","gaus(0)+gaus(3)");
  DoubleGauss_s3->SetParameter(0,r1_s3->Parameter(0));
  DoubleGauss_s3->SetParameter(1,r1_s3->Parameter(1));
  DoubleGauss_s3->SetParameter(2,r1_s3->Parameter(2));
  DoubleGauss_s3->SetParameter(3,10);
  DoubleGauss_s3->SetParameter(4,r2_s3->Parameter(1));
  DoubleGauss_s3->SetParameter(5,r2_s3->Parameter(2));
  RecoDiff_s3->Fit(DoubleGauss_s3);
  
  h1->Add(ProtonMom);
  h1->Add(KaonMom);
  h1->Add(MuonMom);
  h1->Add(ElecMom);
  h1->Add(PionMom);
  
  h_s2->Add(ProtonMom_s2);
  h_s2->Add(KaonMom_s2);
  h_s2->Add(MuonMom_s2);
  h_s2->Add(ElecMom_s2);
  h_s2->Add(PionMom_s2);
  
  h_s3->Add(ProtonMom_s3);
  h_s3->Add(KaonMom_s3);
  h_s3->Add(MuonMom_s3);
  h_s3->Add(ElecMom_s3);
  h_s3->Add(PionMom_s3);
 
  AllTrackStack->Add(ProtonMom_all);
  AllTrackStack->Add(KaonMom_all);
  AllTrackStack->Add(MuonMom_all);
  AllTrackStack->Add(ElecMom_all);
  AllTrackStack->Add(PionMom_all);
  
  
  
  h2->Add(ProtonError);
  h2->Add(KaonError);
  h2->Add(MuonError);
  h2->Add(ElecError);
  h2->Add(PionError);
  
  h_s2_e->Add(ProtonError_s2);
  h_s2_e->Add(KaonError_s2);
  h_s2_e->Add(MuonError_s2);
  h_s2_e->Add(ElecError_s2);
  h_s2_e->Add(PionError_s2);
  
  h_s3_e->Add(ProtonError_s3);
  h_s3_e->Add(KaonError_s3);
  h_s3_e->Add(MuonError_s3);
  h_s3_e->Add(ElecError_s3);
  h_s3_e->Add(PionError_s3);
  
  
  std::cout<<"Total Tracks: "<<PionMom->Integral()+ProtonMom->Integral()+ElecMom->Integral()+MuonMom->Integral()+KaonMom->Integral()<<std::endl;
  std::cout<<"Pion Tracks: "<<PionMom->Integral()<<std::endl;
  std::cout<<"Proton Tracks: "<<ProtonMom->Integral()<<std::endl;
  std::cout<<"Electron Tracks: "<<ElecMom->Integral()<<std::endl;
  std::cout<<"Muon Tracks: "<<MuonMom->Integral()<<std::endl;
  std::cout<<"Kaon Tracks: "<<KaonMom->Integral()<<std::endl;
  
  std::cout<<"S2 Total Tracks: "<<PionMom_s2->Integral()+ProtonMom_s2->Integral()+ElecMom_s2->Integral()+MuonMom_s2->Integral()+KaonMom_s2->Integral()<<std::endl;
  std::cout<<"S2 Pion Tracks: "<<PionMom_s2->Integral()<<std::endl;
  std::cout<<"S2 Proton Tracks: "<<ProtonMom_s2->Integral()<<std::endl;
  std::cout<<"S2 Electron Tracks: "<<ElecMom_s2->Integral()<<std::endl;
  std::cout<<"S2Muon Tracks: "<<MuonMom_s2->Integral()<<std::endl;
  std::cout<<"S2 Kaon Tracks: "<<KaonMom_s2->Integral()<<std::endl;
  
  std::cout<<"s3 Total Tracks: "<<PionMom_s3->Integral()+ProtonMom_s3->Integral()+ElecMom_s3->Integral()+MuonMom_s3->Integral()+KaonMom_s3->Integral()<<std::endl;
  std::cout<<"s3 Pion Tracks: "<<PionMom_s3->Integral()<<std::endl;
  std::cout<<"s3 Proton Tracks: "<<ProtonMom_s3->Integral()<<std::endl;
  std::cout<<"s3 Electron Tracks: "<<ElecMom_s3->Integral()<<std::endl;
  std::cout<<"s3 Muon Tracks: "<<MuonMom_s3->Integral()<<std::endl;
  std::cout<<"s3 Kaon Tracks: "<<KaonMom_s3->Integral()<<std::endl;
  
  
  std::cout<<"ALL Total Tracks: "<<PionMom_all->Integral()+ProtonMom_all->Integral()+ElecMom_all->Integral()+MuonMom_all->Integral()+KaonMom_all->Integral()<<std::endl;
  std::cout<<"ALL Pion Tracks: "<<PionMom_all->Integral()<<std::endl;
  std::cout<<"ALL Proton Tracks: "<<ProtonMom_all->Integral()<<std::endl;
  std::cout<<"ALL Electron Tracks: "<<ElecMom_all->Integral()<<std::endl;
  std::cout<<"ALL Muon Tracks: "<<MuonMom_all->Integral()<<std::endl;
  std::cout<<"ALL Kaon Tracks: "<<KaonMom_all->Integral()<<std::endl;
  
  auto c1 = new TCanvas("c1","c1",600,500);
  c1->SetLogy();
  TLegend *leg = new TLegend(0.7020115,0.508475,0.92,0.8);
  leg->SetHeader("64GeV -100A");
  leg->AddEntry(PionMom,"#pi^{-}","f");
  leg->AddEntry(ProtonMom,"#bar{p}","f");
  leg->AddEntry(ElecMom,"e^{-}","f");
  leg->AddEntry(MuonMom,"#mu^{-}","f");
  leg->AddEntry(KaonMom,"K^{-}","f");
  h1->Draw(); 
  h1->SetTitle("Beamline Composition by Particle and Momentum");
  h1->GetXaxis()->SetTitle("Reconstructed Momentum (MeV/c)");
  h1->GetYaxis()->SetTitle("Tracks per 10 MeV/c");
  leg->Draw();
  c1->SaveAs("blarg.png");
  
  auto c2 = new TCanvas("c2","c2",600,500);
  YKink->Draw("colz");
  
  auto c3 = new TCanvas("c3","c3",600,500);
  TLegend *leg2 = new TLegend(0.7020115,0.508475,0.92,0.8);
  leg2->SetHeader("64GeV -100A");
  leg2->AddEntry(PionError,"#pi^{-}","f");
  leg2->AddEntry(ProtonError,"#bar{p}","f");
  leg2->AddEntry(ElecError,"e^{-}","f");
  leg2->AddEntry(MuonError,"#mu^{-}","f");
  leg2->AddEntry(KaonError,"K^{-}","f");
  h2->Draw(); 
  h2->SetTitle("Beamline Composition by Particle and Momentum");
  h2->GetXaxis()->SetTitle("Fractional Error");
  h2->GetYaxis()->SetTitle("Tracks per 10 MeV/c");
  leg2->Draw();
  
  auto c4 = new TCanvas("c4","c4",600,500); 
  RecoComp->GetXaxis()->SetTitle("Truth Pz WC4 (MeV/c)");
  RecoComp->GetYaxis()->SetTitle("Reconstructed Momentum (MeV/c)");
  RecoComp->Draw("colz");
  
  auto c5 = new TCanvas("c5","c5",600,500);
  RecoDiff->GetXaxis()->SetTitle("(Reco-Truth)/Truth");
  RecoDiff->Draw();
  
  auto c6 = new TCanvas("c6","c6",600,500);
  c6->SetLogy();
  TLegend *leg6 = new TLegend(0.7020115,0.508475,0.92,0.8);
  leg6->SetHeader("64GeV -100A");
  leg6->AddEntry(PionMom_s2,"#pi^{-}","f");
  leg6->AddEntry(ProtonMom_s2,"#bar{p}","f");
  leg6->AddEntry(ElecMom_s2,"e^{-}","f");
  leg6->AddEntry(MuonMom_s2,"#mu^{-}","f");
  leg6->AddEntry(KaonMom_s2,"K^{-}","f");
  h_s2->Draw(); 
  h_s2->SetTitle("Miss WC2: Beamline Composition by Particle and Momentum");
  h_s2->GetXaxis()->SetTitle("Reconstructed Momentum (MeV/c)");
  h_s2->GetYaxis()->SetTitle("Tracks per 10 MeV/c");
  leg6->Draw();

  auto c7 = new TCanvas("c7","c7",600,500);
  c7->SetLogy();
  TLegend *leg7 = new TLegend(0.7020115,0.508475,0.92,0.8);
  leg7->SetHeader("64GeV -100A");
  leg7->AddEntry(PionMom_s3,"#pi^{-}","f");
  leg7->AddEntry(ProtonMom_s3,"#bar{p}","f");
  leg7->AddEntry(ElecMom_s3,"e^{-}","f");
  leg7->AddEntry(MuonMom_s3,"#mu^{-}","f");
  leg7->AddEntry(KaonMom_s3,"K^{-}","f");
  h_s3->Draw(); 
  h_s3->SetTitle("Miss WC3: Beamline Composition by Particle and Momentum");
  h_s3->GetXaxis()->SetTitle("Reconstructed Momentum (MeV/c)");
  h_s3->GetYaxis()->SetTitle("Tracks per 10 MeV/c");
  leg7->Draw();
  
  auto c8 = new TCanvas("c8","c8",600,500);
  TLegend *leg8 = new TLegend(0.7020115,0.508475,0.92,0.8);
  leg8->SetHeader("64GeV -100A");
  leg8->AddEntry(PionError,"#pi^{-}","f");
  leg8->AddEntry(ProtonError,"#bar{p}","f");
  leg8->AddEntry(ElecError,"e^{-}","f");
  leg8->AddEntry(MuonError,"#mu^{-}","f");
  leg8->AddEntry(KaonError,"K^{-}","f");
  h_s2_e->Draw(); 
  h_s2_e->SetTitle("Miss WC2: Beamline Composition by Particle and Momentum");
  h_s2_e->GetXaxis()->SetTitle("Fractional Error");
  h_s2_e->GetYaxis()->SetTitle("Tracks per 10 MeV/c"); 
  leg8->Draw();
  
  auto c9 = new TCanvas("c9","c9",600,500);
  TLegend *leg9 = new TLegend(0.7020115,0.508475,0.92,0.8);
  leg9->SetHeader("64GeV -100A");
  leg9->AddEntry(PionError,"#pi^{-}","f");
  leg9->AddEntry(ProtonError,"#bar{p}","f");
  leg9->AddEntry(ElecError,"e^{-}","f");
  leg9->AddEntry(MuonError,"#mu^{-}","f");
  leg9->AddEntry(KaonError,"K^{-}","f");
  h_s3_e->Draw(); 
  h_s3_e->SetTitle("Miss WC3: Beamline Composition by Particle and Momentum");
  h_s3_e->GetXaxis()->SetTitle("Fractional Error");
  h_s3_e->GetYaxis()->SetTitle("Tracks per 10 MeV/c"); 
  leg9->Draw(); 
  
  auto c10 = new TCanvas("c10","c10",600,500); 
  RecoComp_s2->GetXaxis()->SetTitle("Truth Pz WC4 (MeV/c)");
  RecoComp_s2->GetYaxis()->SetTitle("Reconstructed Momentum (MeV/c)");
  RecoComp_s2->Draw("colz");
  
  auto c11 = new TCanvas("c11","c11",600,500);
  RecoDiff_s2->GetXaxis()->SetTitle("(Reco-Truth)/Truth");
  RecoDiff_s2->Draw();
  
  
  
  auto c12 = new TCanvas("c12","c12",600,500); 
  RecoComp_s3->GetXaxis()->SetTitle("Truth Pz WC4 (MeV/c)");
  RecoComp_s3->GetYaxis()->SetTitle("Reconstructed Momentum (MeV/c)");
  RecoComp_s3->Draw("colz");
  
  auto c13 = new TCanvas("c13","c13",600,500);
  RecoDiff_s3->GetXaxis()->SetTitle("(Reco-Truth)/Truth");
  RecoDiff_s3->Draw();  
  
  auto c14 = new TCanvas("c14","c14",600,500);
  c14->SetLogy();
  TLegend *leg14 = new TLegend(0.7020115,0.508475,0.92,0.8);
  leg14->SetHeader("64GeV -100A");
  leg14->AddEntry(PionMom_all,"#pi^{-}","f");
  leg14->AddEntry(ProtonMom_all,"#bar{p}","f");
  leg14->AddEntry(ElecMom_all,"e^{-}","f");
  leg14->AddEntry(MuonMom_all,"#mu^{-}","f");
  leg14->AddEntry(KaonMom_all,"K^{-}","f");
  AllTrackStack->Draw(); 
  AllTrackStack->SetTitle("Beamline Composition by Particle and Momentum");
  AllTrackStack->GetXaxis()->SetTitle("Reconstructed Momentum (MeV/c)");
  AllTrackStack->GetYaxis()->SetTitle("Tracks per 10 MeV/c");
  leg14->Draw();
}
