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
(assert (= n8 (* n7 n6)))
(declare-fun n9 () Int)
(assert (= n9 (+ n6 n8)))
(declare-fun n10 () Int)
(assert (= n10 (* n7 n7)))
(declare-fun n11 () Int)
(assert (= n11 (* n5 n9)))
(declare-fun n12 () Int)
(assert (= n12 (+ n4 n11)))
(declare-fun n13 () Int)
(assert (= n13 (* n5 n10)))
(declare-fun n14 () Int)
(assert (= n14 (* n13 n6)))
(declare-fun n15 () Int)
(assert (= n15 (+ n12 n14)))
(declare-fun n16 () Int)
(assert (= n16 (* n13 n7)))
(declare-fun n17 () Int)
(assert (= n17 (* n3 n6)))
(declare-fun n18 () Int)
(assert (= n18 (+ n2 n17)))
(declare-fun n19 () Int)
(assert (= n19 (* n3 n7)))
(declare-fun n20 () Int)
(assert (= n20 (* n19 n15)))
(declare-fun n21 () Int)
(assert (= n21 (+ n18 n20)))
(declare-fun n22 () Int)
(assert (= n22 (* n19 n16)))
(declare-fun n23 () Int)
(assert (= n23 (* n3 n9)))
(declare-fun n24 () Int)
(assert (= n24 (+ n2 n23)))
(declare-fun n25 () Int)
(assert (= n25 (* n3 n10)))
(declare-fun n26 () Int)
(assert (= n26 (* n7 n4)))
(declare-fun n27 () Int)
(assert (= n27 (+ n6 n26)))
(declare-fun n28 () Int)
(assert (= n28 (* n7 n5)))
(declare-fun n29 () Int)
(assert (= n29 (* n13 n9)))
(declare-fun n30 () Int)
(assert (= n30 (+ n12 n29)))
(declare-fun n31 () Int)
(assert (= n31 (* n13 n10)))
(declare-fun n32 () Int)
(assert (= n32 (* n25 n9)))
(declare-fun n33 () Int)
(assert (= n33 (+ n24 n32)))
(declare-fun n34 () Int)
(assert (= n34 (* n25 n10)))
(declare-fun n35 () Int)
(assert (= n35 (* n34 n4)))
(declare-fun n36 () Int)
(assert (= n36 (+ n33 n35)))
(declare-fun n37 () Int)
(assert (= n37 (* n34 n5)))
(assert (>= n21 n36))
(assert (>= n22 n37))
(declare-fun n38 () Int)
(assert (= n38 (* n25 n27)))
(declare-fun n39 () Int)
(assert (= n39 (+ n24 n38)))
(declare-fun n40 () Int)
(assert (= n40 (* n25 n28)))
(assert (>= n21 n39))
(assert (>= n22 n40))
(declare-fun n41 () Int)
(assert (= n41 (* n25 n4)))
(declare-fun n42 () Int)
(assert (= n42 (+ n24 n41)))
(declare-fun n43 () Int)
(assert (= n43 (* n25 n5)))
(assert (>= n21 n42))
(assert (>= n22 n43))
(declare-fun n44 () Int)
(assert (= n44 (* n19 n4)))
(declare-fun n45 () Int)
(assert (= n45 (+ n18 n44)))
(declare-fun n46 () Int)
(assert (= n46 (* n19 n5)))
(assert (>= n21 n45))
(assert (>= n22 n46))
(declare-fun n47 () Int)
(assert (= n47 (* n3 n4)))
(declare-fun n48 () Int)
(assert (= n48 (+ n2 n47)))
(declare-fun n49 () Int)
(assert (= n49 (* n3 n5)))
(assert (>= n21 n48))
(assert (>= n22 n49))
(declare-fun n50 () Int)
(assert (= n50 (* n10 n15)))
(declare-fun n51 () Int)
(assert (= n51 (+ n9 n50)))
(declare-fun n52 () Int)
(assert (= n52 (* n10 n16)))
(declare-fun n53 () Int)
(assert (= n53 (* n31 n27)))
(declare-fun n54 () Int)
(assert (= n54 (+ n30 n53)))
(declare-fun n55 () Int)
(assert (= n55 (* n31 n28)))
(assert (>= n51 n54))
(assert (>= n52 n55))
(assert (or (> n21 n36) (> n21 n39) (> n21 n42) (> n21 n45) (> n21 n48)))
(check-sat)
(exit)
