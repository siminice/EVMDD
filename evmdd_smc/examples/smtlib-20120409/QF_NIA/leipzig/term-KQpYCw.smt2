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
(assert (= n16 (* n9 n10)))
(declare-fun n17 () Int)
(assert (= n17 (+ n8 n16)))
(declare-fun n18 () Int)
(assert (= n18 (* n9 n11)))
(declare-fun n19 () Int)
(assert (= n19 (* n11 n10)))
(declare-fun n20 () Int)
(assert (= n20 (+ n10 n19)))
(declare-fun n21 () Int)
(assert (= n21 (* n11 n11)))
(declare-fun n22 () Int)
(assert (= n22 (* n13 n8)))
(declare-fun n23 () Int)
(assert (= n23 (+ n12 n22)))
(declare-fun n24 () Int)
(assert (= n24 (* n13 n9)))
(declare-fun n25 () Int)
(assert (= n25 (* n3 n14)))
(declare-fun n26 () Int)
(assert (= n26 (+ n2 n25)))
(declare-fun n27 () Int)
(assert (= n27 (* n3 n15)))
(declare-fun n28 () Int)
(assert (= n28 (* n5 n10)))
(declare-fun n29 () Int)
(assert (= n29 (+ n4 n28)))
(declare-fun n30 () Int)
(assert (= n30 (* n5 n11)))
(declare-fun n31 () Int)
(assert (= n31 (* n5 n17)))
(declare-fun n32 () Int)
(assert (= n32 (+ n4 n31)))
(declare-fun n33 () Int)
(assert (= n33 (* n5 n18)))
(declare-fun n34 () Int)
(assert (= n34 (* n5 n8)))
(declare-fun n35 () Int)
(assert (= n35 (+ n4 n34)))
(declare-fun n36 () Int)
(assert (= n36 (* n5 n9)))
(assert (>= n32 n35))
(assert (>= n33 n36))
(declare-fun n37 () Int)
(assert (= n37 (* n1 n14)))
(declare-fun n38 () Int)
(assert (= n38 (+ n0 n37)))
(declare-fun n39 () Int)
(assert (= n39 (* n1 n15)))
(assert (>= n38 n2))
(assert (>= n39 n3))
(declare-fun n40 () Int)
(assert (= n40 (* n5 n12)))
(declare-fun n41 () Int)
(assert (= n41 (+ n4 n40)))
(declare-fun n42 () Int)
(assert (= n42 (* n5 n13)))
(assert (>= n29 n41))
(assert (>= n30 n42))
(assert (>= n29 n4))
(assert (>= n30 n5))
(declare-fun n43 () Int)
(assert (= n43 (* n5 n14)))
(declare-fun n44 () Int)
(assert (= n44 (+ n4 n43)))
(declare-fun n45 () Int)
(assert (= n45 (* n5 n15)))
(assert (>= n44 n4))
(assert (>= n45 n5))
(declare-fun n46 () Int)
(assert (= n46 (* n3 n10)))
(declare-fun n47 () Int)
(assert (= n47 (+ n2 n46)))
(declare-fun n48 () Int)
(assert (= n48 (* n3 n11)))
(assert (>= n26 n47))
(assert (>= n27 n48))
(assert (>= n26 n2))
(assert (>= n27 n3))
(declare-fun n49 () Int)
(assert (= n49 (* n11 n8)))
(declare-fun n50 () Int)
(assert (= n50 (+ n10 n49)))
(declare-fun n51 () Int)
(assert (= n51 (* n11 n9)))
(declare-fun n52 () Int)
(assert (= n52 (* n18 n20)))
(declare-fun n53 () Int)
(assert (= n53 (+ n17 n52)))
(declare-fun n54 () Int)
(assert (= n54 (* n18 n21)))
(assert (>= n50 n53))
(assert (>= n51 n54))
(declare-fun n55 () Int)
(assert (= n55 (* n11 n17)))
(declare-fun n56 () Int)
(assert (= n56 (+ n10 n55)))
(declare-fun n57 () Int)
(assert (= n57 (* n11 n18)))
(declare-fun n58 () Int)
(assert (= n58 (* n9 n12)))
(declare-fun n59 () Int)
(assert (= n59 (+ n8 n58)))
(declare-fun n60 () Int)
(assert (= n60 (* n9 n13)))
(assert (>= n56 n59))
(assert (>= n57 n60))
(assert (>= n23 n17))
(assert (>= n24 n18))
(declare-fun n61 () Int)
(assert (= n61 (* n13 n17)))
(declare-fun n62 () Int)
(assert (= n62 (+ n12 n61)))
(declare-fun n63 () Int)
(assert (= n63 (* n13 n18)))
(declare-fun n64 () Int)
(assert (= n64 (* n15 n23)))
(declare-fun n65 () Int)
(assert (= n65 (+ n14 n64)))
(declare-fun n66 () Int)
(assert (= n66 (* n15 n24)))
(assert (>= n62 n65))
(assert (>= n63 n66))
(declare-fun n67 () Int)
(assert (= n67 (* n9 n14)))
(declare-fun n68 () Int)
(assert (= n68 (+ n8 n67)))
(declare-fun n69 () Int)
(assert (= n69 (* n9 n15)))
(assert (>= n68 n17))
(assert (>= n69 n18))
(declare-fun n70 () Int)
(assert (= n70 (* n13 n10)))
(declare-fun n71 () Int)
(assert (= n71 (+ n12 n70)))
(declare-fun n72 () Int)
(assert (= n72 (* n13 n11)))
(declare-fun n73 () Int)
(assert (= n73 (* n13 n12)))
(declare-fun n74 () Int)
(assert (= n74 (+ n12 n73)))
(declare-fun n75 () Int)
(assert (= n75 (* n13 n13)))
(assert (>= n71 n74))
(assert (>= n72 n75))
(declare-fun n76 () Int)
(assert (= n76 (* n13 n14)))
(declare-fun n77 () Int)
(assert (= n77 (+ n12 n76)))
(declare-fun n78 () Int)
(assert (= n78 (* n13 n15)))
(declare-fun n79 () Int)
(assert (= n79 (* n15 n12)))
(declare-fun n80 () Int)
(assert (= n80 (+ n14 n79)))
(declare-fun n81 () Int)
(assert (= n81 (* n15 n13)))
(assert (>= n77 n80))
(assert (>= n78 n81))
(declare-fun n82 () Int)
(assert (= n82 (* n11 n14)))
(declare-fun n83 () Int)
(assert (= n83 (+ n10 n82)))
(declare-fun n84 () Int)
(assert (= n84 (* n11 n15)))
(assert (>= n83 n20))
(assert (>= n84 n21))
(assert (or (> n32 n35) (> n38 n2) (> n29 n41) (> n29 n4) (> n44 n4) (> n26 n47) (> n26 n2)))
(check-sat)
(exit)