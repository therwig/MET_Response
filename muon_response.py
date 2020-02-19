import ROOT

f = ROOT.TFile("/afs/cern.ch/work/d/daekwon/public/l1samples/perfNano_DY_M50_wGenInfo.root")
t = f.Get("Events")

t.SetBranchStatus("*",0)
t.SetBranchStatus("nGenPart",1)
t.SetBranchStatus("GenPart_pt",1)
t.SetBranchStatus("GenPart_eta",1)
t.SetBranchStatus("GenPart_phi",1)
t.SetBranchStatus("GenPart_statusFlags",1)
t.SetBranchStatus("GenPart_pdgId",1)
t.SetBranchStatus("nPFMu",1)
t.SetBranchStatus("PFMu_pt",1)
t.SetBranchStatus("PFMu_eta",1)
t.SetBranchStatus("PFMu_phi",1)

fout = ROOT.TFile("out.root","recreate")

h_resp = ROOT.TProfile("h_resp","h_resp",20,0,200,0,2,"s")
h_nMatch = ROOT.TH1F("h_nMatch","h_nMatch",8,-0.5,7.5)
h_gen = ROOT.TH1F("h_gen","h_gen",20,0,200)
h_pf = ROOT.TH1F("h_pf","h_pf",20,0,200)
h_gen_eta = ROOT.TH1F("h_gen_eta","h_gen_eta",18,-3,3)
h_pf_eta = ROOT.TH1F("h_pf_eta","h_pf_eta",18,-3,3)

hists=[
    h_resp,
    h_nMatch,
    h_gen,
    h_pf,
    h_gen_eta,
    h_pf_eta,
]
for h in hists: h.Sumw2()

v1 = ROOT.TLorentzVector()
v2 = ROOT.TLorentzVector()
nmatch=0

for ei,e in enumerate(t):
    if ei>=10000: break
    
    genMuonIndexes = [i for i,p in enumerate(e.GenPart_statusFlags) if (abs(e.GenPart_pdgId[i])==13 and p&1 and (p&(1<<13)))]
    if len(genMuonIndexes)<2: continue

    nmatch=0
    for ip in range(e.nPFMu):
        v1.SetPtEtaPhiM(e.PFMu_pt[ip],e.PFMu_eta[ip],e.PFMu_phi[ip],0.1)
        for ig in genMuonIndexes:
            v2.SetPtEtaPhiM(e.GenPart_pt[ig],e.GenPart_eta[ig],e.GenPart_phi[ig],0.1)
            if v1.DeltaR(v2) < 0.1:
                nmatch+=1
                h_resp.Fill(e.GenPart_pt[ig], e.PFMu_pt[ip]/e.GenPart_pt[ig] if e.GenPart_pt[ig] else 0.)
                h_pf.Fill(e.PFMu_pt[ip])
                h_gen.Fill(e.GenPart_pt[ig])
                h_pf_eta.Fill(e.PFMu_eta[ip])
                h_gen_eta.Fill(e.GenPart_eta[ig])

    h_nMatch.Fill(nmatch)

c = ROOT.TCanvas("canv","",750,750)
for h in hists:
    h.Write()
    h.Draw()
    c.SaveAs(h.GetName()+".pdf")
# h_nMatch.Write()
# h_resp.Write()
# h_gen.Write()
# h_pf.Write()
# h_gen_eta.Write()
# h_pf_eta.Write()

fout.Close()
