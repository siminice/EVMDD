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
(declare-fun P_5 () Bool)
(declare-fun P_6 () Int)
(assert (<= 0 P_2))
(assert (<= P_2 4294967295))
(assert (<= 0 P_3))
(assert (<= P_3 4294967295))
(assert (<= 0 P_4))
(assert (<= P_4 4294967295))
(assert (<= 0 P_6))
(assert (<= P_6 2147483647))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_1 (* (- P_2 P_3) P_4)) (?v_2 (+ (ite P_5 2147483648 0) P_6)) (?v_0 (* 1 (- 1)))) (= (+ (* 4294967296 dz) rz) (- (+ (+ ?v_1 (* (+ P_6 1) 2)) (+ (- ?v_0 P_2) (- ?v_0 P_4))) (+ ?v_1 (- (- ?v_2 P_2) (- P_4 ?v_2)))))))
(assert (> rz 0))
(assert (< rz 4294967296))
(check-sat)
(exit)
