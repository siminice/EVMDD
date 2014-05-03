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
(declare-fun n18 () Int)
(assert (>= n18 0))
(declare-fun n19 () Int)
(assert (>= n19 0))
(declare-fun n20 () Int)
(assert (>= n20 0))
(declare-fun n21 () Int)
(assert (>= n21 0))
(declare-fun n22 () Int)
(assert (>= n22 0))
(declare-fun n23 () Int)
(assert (>= n23 0))
(declare-fun n24 () Int)
(assert (>= n24 0))
(declare-fun n25 () Int)
(assert (>= n25 0))
(declare-fun n26 () Int)
(assert (>= n26 0))
(declare-fun n27 () Int)
(assert (>= n27 0))
(declare-fun n28 () Int)
(assert (>= n28 0))
(declare-fun n29 () Int)
(assert (>= n29 0))
(declare-fun n30 () Int)
(assert (>= n30 0))
(declare-fun n31 () Int)
(assert (>= n31 0))
(declare-fun n32 () Int)
(assert (= n32 (* n31 n18)))
(declare-fun n33 () Int)
(assert (= n33 (+ n30 n32)))
(declare-fun n34 () Int)
(assert (= n34 (* n31 n19)))
(declare-fun n35 () Int)
(assert (= n35 (* n27 n18)))
(declare-fun n36 () Int)
(assert (= n36 (+ n26 n35)))
(declare-fun n37 () Int)
(assert (= n37 (* n27 n19)))
(declare-fun n38 () Int)
(assert (= n38 (* n31 n16)))
(declare-fun n39 () Int)
(assert (= n39 (+ n30 n38)))
(declare-fun n40 () Int)
(assert (= n40 (* n31 n17)))
(declare-fun n41 () Int)
(assert (= n41 (* n21 n26)))
(declare-fun n42 () Int)
(assert (= n42 (+ n20 n41)))
(declare-fun n43 () Int)
(assert (= n43 (* n21 n27)))
(declare-fun n44 () Int)
(assert (= n44 (* n25 n22)))
(declare-fun n45 () Int)
(assert (= n45 (+ n24 n44)))
(declare-fun n46 () Int)
(assert (= n46 (* n25 n23)))
(declare-fun n47 () Int)
(assert (= n47 (* n1 n24)))
(declare-fun n48 () Int)
(assert (= n48 (+ n0 n47)))
(declare-fun n49 () Int)
(assert (= n49 (* n1 n25)))
(declare-fun n50 () Int)
(assert (= n50 (* n5 n26)))
(declare-fun n51 () Int)
(assert (= n51 (+ n4 n50)))
(declare-fun n52 () Int)
(assert (= n52 (* n5 n27)))
(declare-fun n53 () Int)
(assert (= n53 (* n5 n33)))
(declare-fun n54 () Int)
(assert (= n54 (+ n4 n53)))
(declare-fun n55 () Int)
(assert (= n55 (* n5 n34)))
(declare-fun n56 () Int)
(assert (= n56 (* n5 n39)))
(declare-fun n57 () Int)
(assert (= n57 (+ n4 n56)))
(declare-fun n58 () Int)
(assert (= n58 (* n5 n40)))
(declare-fun n59 () Int)
(assert (= n59 (* n11 n18)))
(declare-fun n60 () Int)
(assert (= n60 (+ n10 n59)))
(declare-fun n61 () Int)
(assert (= n61 (* n11 n19)))
(declare-fun n62 () Int)
(assert (= n62 (* n11 n20)))
(declare-fun n63 () Int)
(assert (= n63 (+ n10 n62)))
(declare-fun n64 () Int)
(assert (= n64 (* n11 n21)))
(declare-fun n65 () Int)
(assert (= n65 (* n11 n22)))
(declare-fun n66 () Int)
(assert (= n66 (+ n10 n65)))
(declare-fun n67 () Int)
(assert (= n67 (* n11 n23)))
(assert (>= n63 n51))
(assert (>= n64 n52))
(assert (>= n63 n10))
(assert (>= n64 n11))
(declare-fun n68 () Int)
(assert (= n68 (* n7 n26)))
(declare-fun n69 () Int)
(assert (= n69 (+ n6 n68)))
(declare-fun n70 () Int)
(assert (= n70 (* n7 n27)))
(assert (>= n66 n69))
(assert (>= n67 n70))
(assert (>= n66 n10))
(assert (>= n67 n11))
(assert (>= n60 n6))
(assert (>= n61 n7))
(declare-fun n71 () Int)
(assert (= n71 (* n7 n24)))
(declare-fun n72 () Int)
(assert (= n72 (+ n6 n71)))
(declare-fun n73 () Int)
(assert (= n73 (* n7 n25)))
(assert (>= n72 n6))
(assert (>= n73 n7))
(declare-fun n74 () Int)
(assert (= n74 (* n5 n24)))
(declare-fun n75 () Int)
(assert (= n75 (+ n4 n74)))
(declare-fun n76 () Int)
(assert (= n76 (* n5 n25)))
(assert (>= n75 n4))
(assert (>= n76 n5))
(assert (>= n48 n51))
(assert (>= n49 n52))
(assert (>= n48 n10))
(assert (>= n49 n11))
(declare-fun n77 () Int)
(assert (= n77 (* n1 n36)))
(declare-fun n78 () Int)
(assert (= n78 (+ n0 n77)))
(declare-fun n79 () Int)
(assert (= n79 (* n1 n37)))
(assert (>= n54 n78))
(assert (>= n55 n79))
(assert (>= n54 n60))
(assert (>= n55 n61))
(declare-fun n80 () Int)
(assert (= n80 (* n1 n16)))
(declare-fun n81 () Int)
(assert (= n81 (+ n0 n80)))
(declare-fun n82 () Int)
(assert (= n82 (* n1 n17)))
(assert (>= n57 n81))
(assert (>= n58 n82))
(assert (>= n57 n0))
(assert (>= n58 n1))
(declare-fun n83 () Int)
(assert (= n83 (* n27 n20)))
(declare-fun n84 () Int)
(assert (= n84 (+ n26 n83)))
(declare-fun n85 () Int)
(assert (= n85 (* n27 n21)))
(assert (>= n84 n42))
(assert (>= n85 n43))
(declare-fun n86 () Int)
(assert (= n86 (* n27 n22)))
(declare-fun n87 () Int)
(assert (= n87 (+ n26 n86)))
(declare-fun n88 () Int)
(assert (= n88 (* n27 n23)))
(declare-fun n89 () Int)
(assert (= n89 (* n23 n26)))
(declare-fun n90 () Int)
(assert (= n90 (+ n22 n89)))
(declare-fun n91 () Int)
(assert (= n91 (* n23 n27)))
(assert (>= n87 n90))
(assert (>= n88 n91))
(assert (>= n36 n45))
(assert (>= n37 n46))
(declare-fun n92 () Int)
(assert (= n92 (* n23 n24)))
(declare-fun n93 () Int)
(assert (= n93 (+ n22 n92)))
(declare-fun n94 () Int)
(assert (= n94 (* n23 n25)))
(assert (>= n93 n45))
(assert (>= n94 n46))
(declare-fun n95 () Int)
(assert (= n95 (* n21 n24)))
(declare-fun n96 () Int)
(assert (= n96 (+ n20 n95)))
(declare-fun n97 () Int)
(assert (= n97 (* n21 n25)))
(declare-fun n98 () Int)
(assert (= n98 (* n25 n20)))
(declare-fun n99 () Int)
(assert (= n99 (+ n24 n98)))
(declare-fun n100 () Int)
(assert (= n100 (* n25 n21)))
(assert (>= n96 n99))
(assert (>= n97 n100))
(declare-fun n101 () Int)
(assert (= n101 (* n17 n24)))
(declare-fun n102 () Int)
(assert (= n102 (+ n16 n101)))
(declare-fun n103 () Int)
(assert (= n103 (* n17 n25)))
(assert (>= n102 n42))
(assert (>= n103 n43))
(declare-fun n104 () Int)
(assert (= n104 (* n27 n28)))
(declare-fun n105 () Int)
(assert (= n105 (+ n26 n104)))
(declare-fun n106 () Int)
(assert (= n106 (* n27 n29)))
(declare-fun n107 () Int)
(assert (= n107 (* n34 n28)))
(declare-fun n108 () Int)
(assert (= n108 (+ n33 n107)))
(declare-fun n109 () Int)
(assert (= n109 (* n34 n29)))
(assert (>= n105 n108))
(assert (>= n106 n109))
(declare-fun n110 () Int)
(assert (= n110 (* n23 n30)))
(declare-fun n111 () Int)
(assert (= n111 (+ n22 n110)))
(declare-fun n112 () Int)
(assert (= n112 (* n23 n31)))
(assert (>= n111 n33))
(assert (>= n112 n34))
(declare-fun n113 () Int)
(assert (= n113 (* n21 n33)))
(declare-fun n114 () Int)
(assert (= n114 (+ n20 n113)))
(declare-fun n115 () Int)
(assert (= n115 (* n21 n34)))
(declare-fun n116 () Int)
(assert (= n116 (* n40 n36)))
(declare-fun n117 () Int)
(assert (= n117 (+ n39 n116)))
(declare-fun n118 () Int)
(assert (= n118 (* n40 n37)))
(assert (>= n114 n117))
(assert (>= n115 n118))
(declare-fun n119 () Int)
(assert (= n119 (* n21 n39)))
(declare-fun n120 () Int)
(assert (= n120 (+ n20 n119)))
(declare-fun n121 () Int)
(assert (= n121 (* n21 n40)))
(declare-fun n122 () Int)
(assert (= n122 (* n40 n16)))
(declare-fun n123 () Int)
(assert (= n123 (+ n39 n122)))
(declare-fun n124 () Int)
(assert (= n124 (* n40 n17)))
(assert (>= n120 n123))
(assert (>= n121 n124))
(assert (or (> n63 n51) (> n63 n10) (> n66 n69) (> n66 n10) (> n60 n6) (> n72 n6) (> n75 n4) (> n48 n51) (> n48 n10) (> n54 n78) (> n54 n60) (> n57 n81) (> n57 n0)))
(check-sat)
(exit)
