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
(assert (= n16 (* n11 n10)))
(declare-fun n17 () Int)
(assert (= n17 (+ n10 n16)))
(declare-fun n18 () Int)
(assert (= n18 (* n11 n11)))
(declare-fun n19 () Int)
(assert (= n19 (* n13 n12)))
(declare-fun n20 () Int)
(assert (= n20 (+ n12 n19)))
(declare-fun n21 () Int)
(assert (= n21 (* n13 n13)))
(declare-fun n22 () Int)
(assert (= n22 (* n7 n14)))
(declare-fun n23 () Int)
(assert (= n23 (+ n6 n22)))
(declare-fun n24 () Int)
(assert (= n24 (* n7 n15)))
(declare-fun n25 () Int)
(assert (= n25 (* n15 n14)))
(declare-fun n26 () Int)
(assert (= n26 (+ n14 n25)))
(declare-fun n27 () Int)
(assert (= n27 (* n15 n15)))
(declare-fun n28 () Int)
(assert (= n28 (* n9 n8)))
(declare-fun n29 () Int)
(assert (= n29 (+ n8 n28)))
(declare-fun n30 () Int)
(assert (= n30 (* n9 n9)))
(declare-fun n31 () Int)
(assert (= n31 (* n24 n20)))
(declare-fun n32 () Int)
(assert (= n32 (+ n23 n31)))
(declare-fun n33 () Int)
(assert (= n33 (* n24 n21)))
(declare-fun n34 () Int)
(assert (= n34 (* n27 n17)))
(declare-fun n35 () Int)
(assert (= n35 (+ n26 n34)))
(declare-fun n36 () Int)
(assert (= n36 (* n27 n18)))
(declare-fun n37 () Int)
(assert (= n37 (* n3 n10)))
(declare-fun n38 () Int)
(assert (= n38 (+ n2 n37)))
(declare-fun n39 () Int)
(assert (= n39 (* n3 n11)))
(declare-fun n40 () Int)
(assert (= n40 (* n30 n20)))
(declare-fun n41 () Int)
(assert (= n41 (+ n29 n40)))
(declare-fun n42 () Int)
(assert (= n42 (* n30 n21)))
(declare-fun n43 () Int)
(assert (= n43 (* n24 n41)))
(declare-fun n44 () Int)
(assert (= n44 (+ n23 n43)))
(declare-fun n45 () Int)
(assert (= n45 (* n24 n42)))
(declare-fun n46 () Int)
(assert (= n46 (* n39 n35)))
(declare-fun n47 () Int)
(assert (= n47 (+ n38 n46)))
(declare-fun n48 () Int)
(assert (= n48 (* n39 n36)))
(declare-fun n49 () Int)
(assert (= n49 (* n18 n10)))
(declare-fun n50 () Int)
(assert (= n50 (+ n17 n49)))
(declare-fun n51 () Int)
(assert (= n51 (* n18 n11)))
(declare-fun n52 () Int)
(assert (= n52 (* n18 n26)))
(declare-fun n53 () Int)
(assert (= n53 (+ n17 n52)))
(declare-fun n54 () Int)
(assert (= n54 (* n18 n27)))
(declare-fun n55 () Int)
(assert (= n55 (* n18 n17)))
(declare-fun n56 () Int)
(assert (= n56 (+ n17 n55)))
(declare-fun n57 () Int)
(assert (= n57 (* n18 n18)))
(declare-fun n58 () Int)
(assert (= n58 (* n18 n50)))
(declare-fun n59 () Int)
(assert (= n59 (+ n17 n58)))
(declare-fun n60 () Int)
(assert (= n60 (* n18 n51)))
(declare-fun n61 () Int)
(assert (= n61 (* n27 n20)))
(declare-fun n62 () Int)
(assert (= n62 (+ n26 n61)))
(declare-fun n63 () Int)
(assert (= n63 (* n27 n21)))
(declare-fun n64 () Int)
(assert (= n64 (* n3 n59)))
(declare-fun n65 () Int)
(assert (= n65 (+ n2 n64)))
(declare-fun n66 () Int)
(assert (= n66 (* n3 n60)))
(declare-fun n67 () Int)
(assert (= n67 (* n30 n17)))
(declare-fun n68 () Int)
(assert (= n68 (+ n29 n67)))
(declare-fun n69 () Int)
(assert (= n69 (* n30 n18)))
(declare-fun n70 () Int)
(assert (= n70 (* n24 n17)))
(declare-fun n71 () Int)
(assert (= n71 (+ n23 n70)))
(declare-fun n72 () Int)
(assert (= n72 (* n24 n18)))
(assert (>= n47 n71))
(assert (>= n48 n72))
(declare-fun n73 () Int)
(assert (= n73 (* n7 n17)))
(declare-fun n74 () Int)
(assert (= n74 (+ n6 n73)))
(declare-fun n75 () Int)
(assert (= n75 (* n7 n18)))
(assert (>= n47 n74))
(assert (>= n48 n75))
(assert (>= n47 n38))
(assert (>= n48 n39))
(assert (>= n47 n2))
(assert (>= n48 n3))
(declare-fun n76 () Int)
(assert (= n76 (* n39 n20)))
(declare-fun n77 () Int)
(assert (= n77 (+ n38 n76)))
(declare-fun n78 () Int)
(assert (= n78 (* n39 n21)))
(assert (>= n65 n77))
(assert (>= n66 n78))
(declare-fun n79 () Int)
(assert (= n79 (* n3 n20)))
(declare-fun n80 () Int)
(assert (= n80 (+ n2 n79)))
(declare-fun n81 () Int)
(assert (= n81 (* n3 n21)))
(assert (>= n65 n80))
(assert (>= n66 n81))
(declare-fun n82 () Int)
(assert (= n82 (* n39 n26)))
(declare-fun n83 () Int)
(assert (= n83 (+ n38 n82)))
(declare-fun n84 () Int)
(assert (= n84 (* n39 n27)))
(assert (>= n32 n83))
(assert (>= n33 n84))
(declare-fun n85 () Int)
(assert (= n85 (* n3 n26)))
(declare-fun n86 () Int)
(assert (= n86 (+ n2 n85)))
(declare-fun n87 () Int)
(assert (= n87 (* n3 n27)))
(assert (>= n32 n86))
(assert (>= n33 n87))
(assert (>= n32 n23))
(assert (>= n33 n24))
(assert (>= n32 n6))
(assert (>= n33 n7))
(declare-fun n88 () Int)
(assert (= n88 (* n24 n53)))
(declare-fun n89 () Int)
(assert (= n89 (+ n23 n88)))
(declare-fun n90 () Int)
(assert (= n90 (* n24 n54)))
(assert (>= n32 n89))
(assert (>= n33 n90))
(declare-fun n91 () Int)
(assert (= n91 (* n7 n53)))
(declare-fun n92 () Int)
(assert (= n92 (+ n6 n91)))
(declare-fun n93 () Int)
(assert (= n93 (* n7 n54)))
(assert (>= n32 n92))
(assert (>= n33 n93))
(declare-fun n94 () Int)
(assert (= n94 (* n3 n50)))
(declare-fun n95 () Int)
(assert (= n95 (+ n2 n94)))
(declare-fun n96 () Int)
(assert (= n96 (* n3 n51)))
(assert (>= n44 n95))
(assert (>= n45 n96))
(declare-fun n97 () Int)
(assert (= n97 (* n3 n17)))
(declare-fun n98 () Int)
(assert (= n98 (+ n2 n97)))
(declare-fun n99 () Int)
(assert (= n99 (* n3 n18)))
(assert (>= n44 n98))
(assert (>= n45 n99))
(assert (>= n44 n38))
(assert (>= n45 n39))
(assert (>= n44 n2))
(assert (>= n45 n3))
(declare-fun n100 () Int)
(assert (= n100 (* n18 n35)))
(declare-fun n101 () Int)
(assert (= n101 (+ n17 n100)))
(declare-fun n102 () Int)
(assert (= n102 (* n18 n36)))
(declare-fun n103 () Int)
(assert (= n103 (* n21 n35)))
(declare-fun n104 () Int)
(assert (= n104 (+ n20 n103)))
(declare-fun n105 () Int)
(assert (= n105 (* n21 n36)))
(assert (>= n101 n104))
(assert (>= n102 n105))
(declare-fun n106 () Int)
(assert (= n106 (* n57 n17)))
(declare-fun n107 () Int)
(assert (= n107 (+ n56 n106)))
(declare-fun n108 () Int)
(assert (= n108 (* n57 n18)))
(declare-fun n109 () Int)
(assert (= n109 (* n69 n20)))
(declare-fun n110 () Int)
(assert (= n110 (+ n68 n109)))
(declare-fun n111 () Int)
(assert (= n111 (* n69 n21)))
(assert (>= n107 n110))
(assert (>= n108 n111))
(assert (>= n62 n53))
(assert (>= n63 n54))
(declare-fun n112 () Int)
(assert (= n112 (* n36 n26)))
(declare-fun n113 () Int)
(assert (= n113 (+ n35 n112)))
(declare-fun n114 () Int)
(assert (= n114 (* n36 n27)))
(assert (>= n62 n113))
(assert (>= n63 n114))
(declare-fun n115 () Int)
(assert (= n115 (* n27 n41)))
(declare-fun n116 () Int)
(assert (= n116 (+ n26 n115)))
(declare-fun n117 () Int)
(assert (= n117 (* n27 n42)))
(assert (>= n116 n56))
(assert (>= n117 n57))
(assert (or (> n47 n71) (> n47 n74) (> n47 n38) (> n47 n2) (> n65 n77) (> n65 n80) (> n32 n83) (> n32 n86) (> n32 n23) (> n32 n6) (> n32 n89) (> n32 n92) (> n44 n95) (> n44 n98) (> n44 n38) (> n44 n2)))
(check-sat)
(exit)
