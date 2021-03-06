(set-logic QF_NIA)
(set-info :source |
    Sequential equivalence checking.
    Calypto Design Systems, Inc. <www.calypto.com>
  |)
(set-info :smt-lib-version 2.0)
(set-info :category "industrial")
(set-info :status unsat)
(declare-fun P_2 () Int)
(declare-fun P_3 () Int)
(declare-fun P_4 () Int)
(declare-fun P_5 () Int)
(declare-fun P_6 () Bool)
(assert (<= 0 P_2))
(assert (<= P_2 127))
(assert (<= 0 P_3))
(assert (<= P_3 255))
(assert (<= 0 P_4))
(assert (<= P_4 255))
(assert (<= 0 P_5))
(assert (<= P_5 255))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_0 (+ (ite P_6 128 0) P_2)) (?v_1 (* P_4 P_5))) (= (+ (* 256 dz) rz) (- (+ (+ (- (+ ?v_0 P_4) P_3) ?v_1) ?v_0) (+ (- (* P_2 2) P_3) (+ P_4 ?v_1))))))
(assert (> rz 0))
(assert (< rz 256))
(check-sat)
(exit)
