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
(assert (= n12 (* n1 n8)))
(declare-fun n13 () Int)
(assert (= n13 (+ n0 n12)))
(declare-fun n14 () Int)
(assert (= n14 (* n1 n9)))
(declare-fun n15 () Int)
(assert (= n15 (* n11 n6)))
(declare-fun n16 () Int)
(assert (= n16 (+ n10 n15)))
(declare-fun n17 () Int)
(assert (= n17 (* n11 n7)))
(declare-fun n18 () Int)
(assert (= n18 (* n11 n8)))
(declare-fun n19 () Int)
(assert (= n19 (+ n10 n18)))
(declare-fun n20 () Int)
(assert (= n20 (* n11 n9)))
(declare-fun n21 () Int)
(assert (= n21 (* n5 n6)))
(declare-fun n22 () Int)
(assert (= n22 (+ n4 n21)))
(declare-fun n23 () Int)
(assert (= n23 (* n5 n7)))
(declare-fun n24 () Int)
(assert (= n24 (* n23 n16)))
(declare-fun n25 () Int)
(assert (= n25 (+ n22 n24)))
(declare-fun n26 () Int)
(assert (= n26 (* n23 n17)))
(assert (>= n13 n25))
(assert (>= n14 n26))
(declare-fun n27 () Int)
(assert (= n27 (* n1 n16)))
(declare-fun n28 () Int)
(assert (= n28 (+ n0 n27)))
(declare-fun n29 () Int)
(assert (= n29 (* n1 n17)))
(assert (>= n13 n28))
(assert (>= n14 n29))
(assert (>= n13 n22))
(assert (>= n14 n23))
(assert (>= n13 n0))
(assert (>= n14 n1))
(assert (>= n6 n8))
(assert (>= n7 n9))
(declare-fun n30 () Int)
(assert (= n30 (* n7 n8)))
(declare-fun n31 () Int)
(assert (= n31 (+ n6 n30)))
(declare-fun n32 () Int)
(assert (= n32 (* n7 n9)))
(declare-fun n33 () Int)
(assert (= n33 (* n17 n16)))
(declare-fun n34 () Int)
(assert (= n34 (+ n16 n33)))
(declare-fun n35 () Int)
(assert (= n35 (* n17 n17)))
(assert (>= n31 n34))
(assert (>= n32 n35))
(declare-fun n36 () Int)
(assert (= n36 (* n20 n10)))
(declare-fun n37 () Int)
(assert (= n37 (+ n19 n36)))
(declare-fun n38 () Int)
(assert (= n38 (* n20 n11)))
(assert (>= n37 n8))
(assert (>= n38 n9))
(assert (or (> n13 n25) (> n13 n28) (> n13 n22) (> n13 n0)))
(check-sat)
(exit)
