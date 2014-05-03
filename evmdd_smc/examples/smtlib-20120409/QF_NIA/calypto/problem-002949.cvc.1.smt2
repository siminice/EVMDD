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
(assert (<= 0 P_2))
(assert (<= P_2 255))
(assert (<= 0 P_3))
(assert (<= P_3 16383))
(assert (<= 0 P_4))
(assert (<= P_4 255))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_0 (* P_3 P_3))) (let ((?v_1 (* P_2 ?v_0))) (= (+ (* 1073741824 dz) rz) (- (ite (not (< 0 P_3)) (* P_4 ?v_0) ?v_1) ?v_1)))))
(assert (> rz 0))
(assert (< rz 1073741824))
(check-sat)
(exit)
