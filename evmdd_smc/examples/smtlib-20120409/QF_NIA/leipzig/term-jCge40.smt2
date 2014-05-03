(set-logic QF_NIA)
(set-info :source |
     Constraint systems stating that a matrix interpretation is
     compatible with a rewriting system (weakly compatible with
     all rules, strictly compatible with at least one).

     Contributed by Johannes Waldmann at HTKW Leipzig.
   |)
(set-info :smt-lib-version 2.0)
(set-info :category "crafted")
(set-info :status sat)
(declare-fun n0 () Int)
(assert (>= n0 0))
(declare-fun n1 () Int)
(assert (>= n1 0))
(declare-fun n2 () Int)
(assert (>= n2 0))
(declare-fun n3 () Int)
(assert (>= n3 0))
(declare-fun n4 () Int)
(assert (>= n4 0))
(declare-fun n5 () Int)
(assert (>= n5 0))
(assert (>= n2 1))
(declare-fun n6 () Int)
(assert (>= n6 0))
(declare-fun n7 () Int)
(assert (>= n7 0))
(declare-fun n8 () Int)
(assert (>= n8 0))
(declare-fun n9 () Int)
(assert (>= n9 0))
(declare-fun n10 () Int)
(assert (>= n10 0))
(declare-fun n11 () Int)
(assert (>= n11 0))
(assert (>= n8 1))
(declare-fun n12 () Int)
(assert (>= n12 0))
(declare-fun n13 () Int)
(assert (>= n13 0))
(declare-fun n14 () Int)
(assert (>= n14 0))
(declare-fun n15 () Int)
(assert (>= n15 0))
(declare-fun n16 () Int)
(assert (>= n16 0))
(declare-fun n17 () Int)
(assert (>= n17 0))
(assert (>= n14 1))
(declare-fun n18 () Int)
(assert (= n18 (* n2 n0)))
(declare-fun n19 () Int)
(assert (= n19 (* n3 n1)))
(declare-fun n20 () Int)
(assert (= n20 (* n4 n0)))
(declare-fun n21 () Int)
(assert (= n21 (* n5 n1)))
(declare-fun n22 () Int)
(assert (= n22 (+ n18 n19)))
(declare-fun n23 () Int)
(assert (= n23 (+ n20 n21)))
(declare-fun n24 () Int)
(assert (= n24 (+ n0 n22)))
(declare-fun n25 () Int)
(assert (= n25 (+ n1 n23)))
(declare-fun n26 () Int)
(assert (= n26 (* n2 n2)))
(declare-fun n27 () Int)
(assert (= n27 (* n3 n4)))
(declare-fun n28 () Int)
(assert (= n28 (* n2 n3)))
(declare-fun n29 () Int)
(assert (= n29 (* n3 n5)))
(declare-fun n30 () Int)
(assert (= n30 (* n4 n2)))
(declare-fun n31 () Int)
(assert (= n31 (* n5 n4)))
(declare-fun n32 () Int)
(assert (= n32 (* n4 n3)))
(declare-fun n33 () Int)
(assert (= n33 (* n5 n5)))
(declare-fun n34 () Int)
(assert (= n34 (+ n26 n27)))
(declare-fun n35 () Int)
(assert (= n35 (+ n28 n29)))
(declare-fun n36 () Int)
(assert (= n36 (+ n30 n31)))
(declare-fun n37 () Int)
(assert (= n37 (+ n32 n33)))
(declare-fun n38 () Int)
(assert (= n38 (* n2 n12)))
(declare-fun n39 () Int)
(assert (= n39 (* n3 n13)))
(declare-fun n40 () Int)
(assert (= n40 (* n4 n12)))
(declare-fun n41 () Int)
(assert (= n41 (* n5 n13)))
(declare-fun n42 () Int)
(assert (= n42 (+ n38 n39)))
(declare-fun n43 () Int)
(assert (= n43 (+ n40 n41)))
(declare-fun n44 () Int)
(assert (= n44 (+ n0 n42)))
(declare-fun n45 () Int)
(assert (= n45 (+ n1 n43)))
(declare-fun n46 () Int)
(assert (= n46 (* n2 n14)))
(declare-fun n47 () Int)
(assert (= n47 (* n3 n16)))
(declare-fun n48 () Int)
(assert (= n48 (* n2 n15)))
(declare-fun n49 () Int)
(assert (= n49 (* n3 n17)))
(declare-fun n50 () Int)
(assert (= n50 (* n4 n14)))
(declare-fun n51 () Int)
(assert (= n51 (* n5 n16)))
(declare-fun n52 () Int)
(assert (= n52 (* n4 n15)))
(declare-fun n53 () Int)
(assert (= n53 (* n5 n17)))
(declare-fun n54 () Int)
(assert (= n54 (+ n46 n47)))
(declare-fun n55 () Int)
(assert (= n55 (+ n48 n49)))
(declare-fun n56 () Int)
(assert (= n56 (+ n50 n51)))
(declare-fun n57 () Int)
(assert (= n57 (+ n52 n53)))
(declare-fun n58 () Int)
(assert (= n58 (* n2 n6)))
(declare-fun n59 () Int)
(assert (= n59 (* n3 n7)))
(declare-fun n60 () Int)
(assert (= n60 (* n4 n6)))
(declare-fun n61 () Int)
(assert (= n61 (* n5 n7)))
(declare-fun n62 () Int)
(assert (= n62 (+ n58 n59)))
(declare-fun n63 () Int)
(assert (= n63 (+ n60 n61)))
(declare-fun n64 () Int)
(assert (= n64 (+ n0 n62)))
(declare-fun n65 () Int)
(assert (= n65 (+ n1 n63)))
(declare-fun n66 () Int)
(assert (= n66 (* n2 n8)))
(declare-fun n67 () Int)
(assert (= n67 (* n3 n10)))
(declare-fun n68 () Int)
(assert (= n68 (* n2 n9)))
(declare-fun n69 () Int)
(assert (= n69 (* n3 n11)))
(declare-fun n70 () Int)
(assert (= n70 (* n4 n8)))
(declare-fun n71 () Int)
(assert (= n71 (* n5 n10)))
(declare-fun n72 () Int)
(assert (= n72 (* n4 n9)))
(declare-fun n73 () Int)
(assert (= n73 (* n5 n11)))
(declare-fun n74 () Int)
(assert (= n74 (+ n66 n67)))
(declare-fun n75 () Int)
(assert (= n75 (+ n68 n69)))
(declare-fun n76 () Int)
(assert (= n76 (+ n70 n71)))
(declare-fun n77 () Int)
(assert (= n77 (+ n72 n73)))
(declare-fun n78 () Int)
(assert (= n78 (* n8 n24)))
(declare-fun n79 () Int)
(assert (= n79 (* n9 n25)))
(declare-fun n80 () Int)
(assert (= n80 (* n10 n24)))
(declare-fun n81 () Int)
(assert (= n81 (* n11 n25)))
(declare-fun n82 () Int)
(assert (= n82 (+ n78 n79)))
(declare-fun n83 () Int)
(assert (= n83 (+ n80 n81)))
(declare-fun n84 () Int)
(assert (= n84 (+ n6 n82)))
(declare-fun n85 () Int)
(assert (= n85 (+ n7 n83)))
(declare-fun n86 () Int)
(assert (= n86 (* n8 n34)))
(declare-fun n87 () Int)
(assert (= n87 (* n9 n36)))
(declare-fun n88 () Int)
(assert (= n88 (* n8 n35)))
(declare-fun n89 () Int)
(assert (= n89 (* n9 n37)))
(declare-fun n90 () Int)
(assert (= n90 (* n10 n34)))
(declare-fun n91 () Int)
(assert (= n91 (* n11 n36)))
(declare-fun n92 () Int)
(assert (= n92 (* n10 n35)))
(declare-fun n93 () Int)
(assert (= n93 (* n11 n37)))
(declare-fun n94 () Int)
(assert (= n94 (+ n86 n87)))
(declare-fun n95 () Int)
(assert (= n95 (+ n88 n89)))
(declare-fun n96 () Int)
(assert (= n96 (+ n90 n91)))
(declare-fun n97 () Int)
(assert (= n97 (+ n92 n93)))
(assert (>= n64 n84))
(assert (>= n65 n85))
(assert (>= n74 n94))
(assert (>= n75 n95))
(assert (>= n76 n96))
(assert (>= n77 n97))
(declare-fun n98 () Int)
(assert (= n98 (* n54 n0)))
(declare-fun n99 () Int)
(assert (= n99 (* n55 n1)))
(declare-fun n100 () Int)
(assert (= n100 (* n56 n0)))
(declare-fun n101 () Int)
(assert (= n101 (* n57 n1)))
(declare-fun n102 () Int)
(assert (= n102 (+ n98 n99)))
(declare-fun n103 () Int)
(assert (= n103 (+ n100 n101)))
(declare-fun n104 () Int)
(assert (= n104 (+ n44 n102)))
(declare-fun n105 () Int)
(assert (= n105 (+ n45 n103)))
(declare-fun n106 () Int)
(assert (= n106 (* n54 n2)))
(declare-fun n107 () Int)
(assert (= n107 (* n55 n4)))
(declare-fun n108 () Int)
(assert (= n108 (* n54 n3)))
(declare-fun n109 () Int)
(assert (= n109 (* n55 n5)))
(declare-fun n110 () Int)
(assert (= n110 (* n56 n2)))
(declare-fun n111 () Int)
(assert (= n111 (* n57 n4)))
(declare-fun n112 () Int)
(assert (= n112 (* n56 n3)))
(declare-fun n113 () Int)
(assert (= n113 (* n57 n5)))
(declare-fun n114 () Int)
(assert (= n114 (+ n106 n107)))
(declare-fun n115 () Int)
(assert (= n115 (+ n108 n109)))
(declare-fun n116 () Int)
(assert (= n116 (+ n110 n111)))
(declare-fun n117 () Int)
(assert (= n117 (+ n112 n113)))
(assert (>= n24 n104))
(assert (>= n25 n105))
(assert (>= n34 n114))
(assert (>= n35 n115))
(assert (>= n36 n116))
(assert (>= n37 n117))
(assert (or (> n64 n84) (> n24 n104)))
(check-sat)
(exit)
