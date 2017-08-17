//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jul 14 11:23:15 2017 by ROOT version 6.08/06
// from TTree EventTree_Spill1/EventTree_Spill1
// found on file: /lariat/data/users/gpulliam/MCdata/64Gev_pos100A/MergedTreeRound1.root
//////////////////////////////////////////////////////////

#ifndef BeamlineComposition_h
#define BeamlineComposition_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class BeamlineComposition {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           SpillID;
   Int_t           EventID;
   Int_t           TrackID;
   Bool_t          TrackPresentDet1;
   Double_t        xDet1;
   Double_t        yDet1;
   Double_t        zDet1;
   Double_t        tDet1;
   Double_t        PxDet1;
   Double_t        PyDet1;
   Double_t        PzDet1;
   Double_t        PDGidDet1;
   Double_t        ParentIDDet1;
   Bool_t          TrackPresentDet2;
   Double_t        xDet2;
   Double_t        yDet2;
   Double_t        zDet2;
   Double_t        tDet2;
   Double_t        PxDet2;
   Double_t        PyDet2;
   Double_t        PzDet2;
   Double_t        PDGidDet2;
   Double_t        ParentIDDet2;
   Bool_t          TrackPresentDet3;
   Double_t        xDet3;
   Double_t        yDet3;
   Double_t        zDet3;
   Double_t        tDet3;
   Double_t        PxDet3;
   Double_t        PyDet3;
   Double_t        PzDet3;
   Double_t        PDGidDet3;
   Double_t        ParentIDDet3;
   Bool_t          TrackPresentDet4;
   Double_t        xDet4;
   Double_t        yDet4;
   Double_t        zDet4;
   Double_t        tDet4;
   Double_t        PxDet4;
   Double_t        PyDet4;
   Double_t        PzDet4;
   Double_t        PDGidDet4;
   Double_t        ParentIDDet4;
   Bool_t          TrackPresentStartLine;
   Double_t        xStartLine;
   Double_t        yStartLine;
   Double_t        zStartLine;
   Double_t        tStartLine;
   Double_t        PxStartLine;
   Double_t        PyStartLine;
   Double_t        PzStartLine;
   Double_t        PDGidStartLine;
   Double_t        ParentIDStartLine;
   Bool_t          TrackPresentTOFus;
   Double_t        xTOFus;
   Double_t        yTOFus;
   Double_t        zTOFus;
   Double_t        tTOFus;
   Double_t        PxTOFus;
   Double_t        PyTOFus;
   Double_t        PzTOFus;
   Double_t        PDGidTOFus;
   Double_t        ParentIDTOFus;
   Bool_t          TrackPresentTOFds;
   Double_t        xTOFds;
   Double_t        yTOFds;
   Double_t        zTOFds;
   Double_t        tTOFds;
   Double_t        PxTOFds;
   Double_t        PyTOFds;
   Double_t        PzTOFds;
   Double_t        PDGidTOFds;
   Double_t        ParentIDTOFds;

   // List of branches
   TBranch        *b_SpillID;   //!
   TBranch        *b_EventID;   //!
   TBranch        *b_TrackID;   //!
   TBranch        *b_TrackPresentDet1;   //!
   TBranch        *b_xDet1;   //!
   TBranch        *b_yDet1;   //!
   TBranch        *b_zDet1;   //!
   TBranch        *b_tDet1;   //!
   TBranch        *b_PxDet1;   //!
   TBranch        *b_PyDet1;   //!
   TBranch        *b_PzDet1;   //!
   TBranch        *b_PDGidDet1;   //!
   TBranch        *b_ParentIDDet1;   //!
   TBranch        *b_TrackPresentDet2;   //!
   TBranch        *b_xDet2;   //!
   TBranch        *b_yDet2;   //!
   TBranch        *b_zDet2;   //!
   TBranch        *b_tDet2;   //!
   TBranch        *b_PxDet2;   //!
   TBranch        *b_PyDet2;   //!
   TBranch        *b_PzDet2;   //!
   TBranch        *b_PDGidDet2;   //!
   TBranch        *b_ParentIDDet2;   //!
   TBranch        *b_TrackPresentDet3;   //!
   TBranch        *b_xDet3;   //!
   TBranch        *b_yDet3;   //!
   TBranch        *b_zDet3;   //!
   TBranch        *b_tDet3;   //!
   TBranch        *b_PxDet3;   //!
   TBranch        *b_PyDet3;   //!
   TBranch        *b_PzDet3;   //!
   TBranch        *b_PDGidDet3;   //!
   TBranch        *b_ParentIDDet3;   //!
   TBranch        *b_TrackPresentDet4;   //!
   TBranch        *b_xDet4;   //!
   TBranch        *b_yDet4;   //!
   TBranch        *b_zDet4;   //!
   TBranch        *b_tDet4;   //!
   TBranch        *b_PxDet4;   //!
   TBranch        *b_PyDet4;   //!
   TBranch        *b_PzDet4;   //!
   TBranch        *b_PDGidDet4;   //!
   TBranch        *b_ParentIDDet4;   //!
   TBranch        *b_TrackPresentStartLine;   //!
   TBranch        *b_xStartLine;   //!
   TBranch        *b_yStartLine;   //!
   TBranch        *b_zStartLine;   //!
   TBranch        *b_tStartLine;   //!
   TBranch        *b_PxStartLine;   //!
   TBranch        *b_PyStartLine;   //!
   TBranch        *b_PzStartLine;   //!
   TBranch        *b_PDGidStartLine;   //!
   TBranch        *b_ParentIDStartLine;   //!
   TBranch        *b_TrackPresentTOFus;   //!
   TBranch        *b_xTOFus;   //!
   TBranch        *b_yTOFus;   //!
   TBranch        *b_zTOFus;   //!
   TBranch        *b_tTOFus;   //!
   TBranch        *b_PxTOFus;   //!
   TBranch        *b_PyTOFus;   //!
   TBranch        *b_PzTOFus;   //!
   TBranch        *b_PDGidTOFus;   //!
   TBranch        *b_ParentIDTOFus;   //!
   TBranch        *b_TrackPresentTOFds;   //!
   TBranch        *b_xTOFds;   //!
   TBranch        *b_yTOFds;   //!
   TBranch        *b_zTOFds;   //!
   TBranch        *b_tTOFds;   //!
   TBranch        *b_PxTOFds;   //!
   TBranch        *b_PyTOFds;   //!
   TBranch        *b_PzTOFds;   //!
   TBranch        *b_PDGidTOFds;   //!
   TBranch        *b_ParentIDTOFds;   //!

   BeamlineComposition(TTree *tree=0);
   virtual ~BeamlineComposition();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef BeamlineComposition_cxx
BeamlineComposition::BeamlineComposition(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("64GeV_pos100A_all.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("64GeV_pos100A_all.root");
      }
      f->GetObject("EventTree_Spill1",tree);

   }
   Init(tree);
}

BeamlineComposition::~BeamlineComposition()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t BeamlineComposition::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t BeamlineComposition::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void BeamlineComposition::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("SpillID", &SpillID, &b_SpillID);
   fChain->SetBranchAddress("EventID", &EventID, &b_EventID);
   fChain->SetBranchAddress("TrackID", &TrackID, &b_TrackID);
   fChain->SetBranchAddress("TrackPresentDet1", &TrackPresentDet1, &b_TrackPresentDet1);
   fChain->SetBranchAddress("xDet1", &xDet1, &b_xDet1);
   fChain->SetBranchAddress("yDet1", &yDet1, &b_yDet1);
   fChain->SetBranchAddress("zDet1", &zDet1, &b_zDet1);
   fChain->SetBranchAddress("tDet1", &tDet1, &b_tDet1);
   fChain->SetBranchAddress("PxDet1", &PxDet1, &b_PxDet1);
   fChain->SetBranchAddress("PyDet1", &PyDet1, &b_PyDet1);
   fChain->SetBranchAddress("PzDet1", &PzDet1, &b_PzDet1);
   fChain->SetBranchAddress("PDGidDet1", &PDGidDet1, &b_PDGidDet1);
   fChain->SetBranchAddress("ParentIDDet1", &ParentIDDet1, &b_ParentIDDet1);
   fChain->SetBranchAddress("TrackPresentDet2", &TrackPresentDet2, &b_TrackPresentDet2);
   fChain->SetBranchAddress("xDet2", &xDet2, &b_xDet2);
   fChain->SetBranchAddress("yDet2", &yDet2, &b_yDet2);
   fChain->SetBranchAddress("zDet2", &zDet2, &b_zDet2);
   fChain->SetBranchAddress("tDet2", &tDet2, &b_tDet2);
   fChain->SetBranchAddress("PxDet2", &PxDet2, &b_PxDet2);
   fChain->SetBranchAddress("PyDet2", &PyDet2, &b_PyDet2);
   fChain->SetBranchAddress("PzDet2", &PzDet2, &b_PzDet2);
   fChain->SetBranchAddress("PDGidDet2", &PDGidDet2, &b_PDGidDet2);
   fChain->SetBranchAddress("ParentIDDet2", &ParentIDDet2, &b_ParentIDDet2);
   fChain->SetBranchAddress("TrackPresentDet3", &TrackPresentDet3, &b_TrackPresentDet3);
   fChain->SetBranchAddress("xDet3", &xDet3, &b_xDet3);
   fChain->SetBranchAddress("yDet3", &yDet3, &b_yDet3);
   fChain->SetBranchAddress("zDet3", &zDet3, &b_zDet3);
   fChain->SetBranchAddress("tDet3", &tDet3, &b_tDet3);
   fChain->SetBranchAddress("PxDet3", &PxDet3, &b_PxDet3);
   fChain->SetBranchAddress("PyDet3", &PyDet3, &b_PyDet3);
   fChain->SetBranchAddress("PzDet3", &PzDet3, &b_PzDet3);
   fChain->SetBranchAddress("PDGidDet3", &PDGidDet3, &b_PDGidDet3);
   fChain->SetBranchAddress("ParentIDDet3", &ParentIDDet3, &b_ParentIDDet3);
   fChain->SetBranchAddress("TrackPresentDet4", &TrackPresentDet4, &b_TrackPresentDet4);
   fChain->SetBranchAddress("xDet4", &xDet4, &b_xDet4);
   fChain->SetBranchAddress("yDet4", &yDet4, &b_yDet4);
   fChain->SetBranchAddress("zDet4", &zDet4, &b_zDet4);
   fChain->SetBranchAddress("tDet4", &tDet4, &b_tDet4);
   fChain->SetBranchAddress("PxDet4", &PxDet4, &b_PxDet4);
   fChain->SetBranchAddress("PyDet4", &PyDet4, &b_PyDet4);
   fChain->SetBranchAddress("PzDet4", &PzDet4, &b_PzDet4);
   fChain->SetBranchAddress("PDGidDet4", &PDGidDet4, &b_PDGidDet4);
   fChain->SetBranchAddress("ParentIDDet4", &ParentIDDet4, &b_ParentIDDet4);
   fChain->SetBranchAddress("TrackPresentStartLine", &TrackPresentStartLine, &b_TrackPresentStartLine);
   fChain->SetBranchAddress("xStartLine", &xStartLine, &b_xStartLine);
   fChain->SetBranchAddress("yStartLine", &yStartLine, &b_yStartLine);
   fChain->SetBranchAddress("zStartLine", &zStartLine, &b_zStartLine);
   fChain->SetBranchAddress("tStartLine", &tStartLine, &b_tStartLine);
   fChain->SetBranchAddress("PxStartLine", &PxStartLine, &b_PxStartLine);
   fChain->SetBranchAddress("PyStartLine", &PyStartLine, &b_PyStartLine);
   fChain->SetBranchAddress("PzStartLine", &PzStartLine, &b_PzStartLine);
   fChain->SetBranchAddress("PDGidStartLine", &PDGidStartLine, &b_PDGidStartLine);
   fChain->SetBranchAddress("ParentIDStartLine", &ParentIDStartLine, &b_ParentIDStartLine);
   fChain->SetBranchAddress("TrackPresentTOFus", &TrackPresentTOFus, &b_TrackPresentTOFus);
   fChain->SetBranchAddress("xTOFus", &xTOFus, &b_xTOFus);
   fChain->SetBranchAddress("yTOFus", &yTOFus, &b_yTOFus);
   fChain->SetBranchAddress("zTOFus", &zTOFus, &b_zTOFus);
   fChain->SetBranchAddress("tTOFus", &tTOFus, &b_tTOFus);
   fChain->SetBranchAddress("PxTOFus", &PxTOFus, &b_PxTOFus);
   fChain->SetBranchAddress("PyTOFus", &PyTOFus, &b_PyTOFus);
   fChain->SetBranchAddress("PzTOFus", &PzTOFus, &b_PzTOFus);
   fChain->SetBranchAddress("PDGidTOFus", &PDGidTOFus, &b_PDGidTOFus);
   fChain->SetBranchAddress("ParentIDTOFus", &ParentIDTOFus, &b_ParentIDTOFus);
   fChain->SetBranchAddress("TrackPresentTOFds", &TrackPresentTOFds, &b_TrackPresentTOFds);
   fChain->SetBranchAddress("xTOFds", &xTOFds, &b_xTOFds);
   fChain->SetBranchAddress("yTOFds", &yTOFds, &b_yTOFds);
   fChain->SetBranchAddress("zTOFds", &zTOFds, &b_zTOFds);
   fChain->SetBranchAddress("tTOFds", &tTOFds, &b_tTOFds);
   fChain->SetBranchAddress("PxTOFds", &PxTOFds, &b_PxTOFds);
   fChain->SetBranchAddress("PyTOFds", &PyTOFds, &b_PyTOFds);
   fChain->SetBranchAddress("PzTOFds", &PzTOFds, &b_PzTOFds);
   fChain->SetBranchAddress("PDGidTOFds", &PDGidTOFds, &b_PDGidTOFds);
   fChain->SetBranchAddress("ParentIDTOFds", &ParentIDTOFds, &b_ParentIDTOFds);
   Notify();
}

Bool_t BeamlineComposition::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void BeamlineComposition::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t BeamlineComposition::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef BeamlineComposition_cxx
