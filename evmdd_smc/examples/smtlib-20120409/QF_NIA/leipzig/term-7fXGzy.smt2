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
(assert (>= n1 1))
(declare-fun n2 () Int)
(assert (>= n2 0))
(declare-fun n3 () Int)
(assert (>= n3 0))
(assert (>= n3 1))
(declare-fun n4 () Int)
(assert (>= n4 0))
(declare-fun n5 () Int)
(assert (>= n5 0))
(assert (>= n5 1))
(declare-fun n6 () Int)
(assert (>= n6 0))
(declare-fun n7 () Int)
(assert (>= n7 0))
(assert (>= n7 1))
(declare-fun n8 () Int)
(assert (= n8 (* n3 n2)))
(declare-fun n9 () Int)
(assert (= n9 (+ n2 n8)))
(declare-fun n10 () Int)
(assert (= n10 (* n3 n3)))
(declare-fun n11 () Int)
(assert (= n11 (* n7 n0)))
(declare-fun n12 () Int)
(assert (= n12 (+ n6 n11)))
(declare-fun n13 () Int)
(assert (= n13 (* n7 n1)))
(declare-fun n14 () Int)
(assert (= n14 (* n7 n4)))
(declare-fun n15 () Int)
(assert (= n15 (+ n6 n14)))
(declare-fun n16 () Int)
(assert (= n16 (* n7 n5)))
(declare-fun n17 () Int)
(assert (= n17 (* n10 n2)))
(declare-fun n18 () Int)
(assert (= n18 (+ n9 n17)))
(declare-fun n19 () Int)
(assert (= n19 (* n10 n3)))
(declare-fun n20 () Int)
(assert (= n20 (* n3 n4)))
(declare-fun n21 () Int)
(assert (= n21 (+ n2 n20)))
(declare-fun n22 () Int)
(assert (= n22 (* n3 n5)))
(declare-fun n23 () Int)
(assert (= n23 (* n5 n0)))
(declare-fun n24 () Int)
(assert (= n24 (+ n4 n23)))
(declare-fun n25 () Int)
(assert (= n25 (* n5 n1)))
(declare-fun n26 () Int)
(assert (= n26 (* n5 n6)))
(declare-fun n27 () Int)
(assert (= n27 (+ n4 n26)))
(declare-fun n28 () Int)
(assert (= n28 (* n5 n7)))
(declare-fun n29 () Int)
(assert (= n29 (* n22 n0)))
(declare-fun n30 () Int)
(assert (= n30 (+ n21 n29)))
(declare-fun n31 () Int)
(assert (= n31 (* n22 n1)))
(declare-fun n32 () Int)
(assert (= n32 (* n1 n2)))
(declare-fun n33 () Int)
(assert (= n33 (+ n0 n32)))
(declare-fun n34 () Int)
(assert (= n34 (* n1 n3)))
(assert (>= n30 n33))
(assert (>= n31 n34))
(declare-fun n35 () Int)
(assert (= n35 (* n25 n4)))
(declare-fun n36 () Int)
(assert (= n36 (+ n24 n35)))
(declare-fun n37 () Int)
(assert (= n37 (* n25 n5)))
(assert (>= n18 n36))
(assert (>= n19 n37))
(assert (>= n27 n15))
(assert (>= n28 n16))
(declare-fun n38 () Int)
(assert (= n38 (* n28 n2)))
(declare-fun n39 () Int)
(assert (= n39 (+ n27 n38)))
(declare-fun n40 () Int)
(assert (= n40 (* n28 n3)))
(declare-fun n41 () Int)
(assert (= n41 (* n16 n4)))
(declare-fun n42 () Int)
(assert (= n42 (+ n15 n41)))
(declare-fun n43 () Int)
(assert (= n43 (* n16 n5)))
(assert (>= n39 n42))
(assert (>= n40 n43))
(assert (>= n15 n18))
(assert (>= n16 n19))
(declare-fun n44 () Int)
(assert (= n44 (* n5 n2)))
(declare-fun n45 () Int)
(assert (= n45 (+ n4 n44)))
(declare-fun n46 () Int)
(assert (= n46 (* n5 n3)))
(assert (>= n45 n12))
(assert (>= n46 n13))
(declare-fun n47 () Int)
(assert (= n47 (* n7 n21)))
(declare-fun n48 () Int)
(assert (= n48 (+ n6 n47)))
(declare-fun n49 () Int)
(assert (= n49 (* n7 n22)))
(declare-fun n50 () Int)
(assert (= n50 (* n1 n0)))
(declare-fun n51 () Int)
(assert (= n51 (+ n0 n50)))
(declare-fun n52 () Int)
(assert (= n52 (* n1 n1)))
(assert (>= n48 n51))
(assert (>= n49 n52))
(assert (>= n12 n2))
(assert (>= n13 n3))
(assert (or (> n30 n33) (> n18 n36) (> n27 n15) (> n39 n42) (> n15 n18) (> n45 n12) (> n48 n51) (> n12 n2)))
(check-sat)
(exit)
