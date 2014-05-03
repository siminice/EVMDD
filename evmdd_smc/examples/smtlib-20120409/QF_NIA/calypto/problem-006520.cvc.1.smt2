(set-logic QF_NIA)
(set-info :source |
    Sequential equivalence checking.
    Calypto Design Systems, Inc. <www.calypto.com>
  |)
(set-info :smt-lib-version 2.0)
(set-info :category "industrial")
(set-info :status unsat)
(declare-fun P_2 () Bool)
(declare-fun P_3 () Int)
(declare-fun P_4 () Int)
(declare-fun P_5 () Int)
(declare-fun P_6 () Int)
(declare-fun P_7 () Int)
(declare-fun P_8 () Int)
(declare-fun P_9 () Int)
(assert (<= 0 P_3))
(assert (<= P_3 255))
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
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_0 (not P_2)) (?v_2 (+ (- P_3 (* (+ P_4 P_5) P_6)) P_7))) (let ((?v_1 (not ?v_0)) (?v_3 (+ P_8 (* P_6 P_4)))) (= (+ (* 256 dz) rz) (- (ite ?v_0 (+ (* (ite ?v_1 (* (+ P_3 P_6) P_7) ?v_2) (ite ?v_1 ?v_2 ?v_3)) (ite ?v_1 ?v_3 P_9)) ?v_2) (ite ?v_0 (+ (* ?v_2 ?v_3) P_9) ?v_2))))))
(assert (> rz 0))
(assert (< rz 256))
(check-sat)
(exit)
