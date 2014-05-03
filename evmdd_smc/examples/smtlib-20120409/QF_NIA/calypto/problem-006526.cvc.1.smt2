(set-logic QF_NIA)
(set-info :source |
    Sequential equivalence checking.
    Calypto Design Systems, Inc. <www.calypto.com>
  |)
(set-info :smt-lib-version 2.0)
(set-info :category "industrial")
(set-info :status unsat)
(declare-fun P_2 () Bool)
(declare-fun P_3 () Bool)
(declare-fun P_4 () Int)
(declare-fun P_5 () Int)
(declare-fun P_6 () Int)
(declare-fun P_7 () Int)
(declare-fun P_8 () Int)
(declare-fun P_9 () Int)
(declare-fun P_10 () Int)
(declare-fun P_11 () Int)
(declare-fun P_14 () Int)
(assert (<= 0 P_4))
(assert (<= P_4 255))
(assert (<= 0 P_5))
(assert (<= P_5 255))
(assert (<= 0 P_6))
(assert (<= P_6 255))
(assert (<= 0 P_7))
(assert (<= P_7 255))
(assert (<= 0 P_8))
(assert (<= P_8 255))
(assert (<= 0 P_9))
(assert (<= P_9 255))
(assert (<= 0 P_10))
(assert (<= P_10 255))
(assert (<= 0 P_11))
(assert (<= P_11 255))
(assert (<= 0 P_14))
(assert (<= P_14 255))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_1 (ite (not P_2) (ite (not P_3) 2 1) 0)) (?v_2 (- (* P_4 P_5) P_6))) (let ((?v_4 (= ?v_1 2)) (?v_3 (= ?v_1 1)) (?v_0 (= ?v_1 0))) (let ((?v_5 (+ (ite ?v_0 ?v_2 (ite ?v_3 ?v_2 (ite ?v_4 (- P_6 P_7) P_8))) (ite ?v_0 P_7 (ite ?v_3 P_7 (ite ?v_4 (- P_9 P_10) P_11)))))) (= (+ (* 256 dz) rz) (- (ite ?v_0 ?v_5 (ite ?v_3 ?v_5 (ite ?v_4 ?v_5 P_14))) ?v_5))))))
(assert (> rz 0))
(assert (< rz 256))
(check-sat)
(exit)
