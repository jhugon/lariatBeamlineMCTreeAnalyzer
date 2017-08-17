void RunBeamlineComposition()
{
  gROOT->ProcessLine(".L BeamlineCompositionMacros/BeamlineComposition.C");
  gROOT->ProcessLine("BeamlineComposition b");
  gROOT->ProcessLine("b.Loop()");
  gROOT->ProcessLine(".q");
}
