void RunTreeCutter()
{
  gROOT->ProcessLine(".L TreeCutter.C");
  gROOT->ProcessLine("TreeCutter t");
  gROOT->ProcessLine("t.Loop()");
  gROOT->ProcessLine(".q");
}
