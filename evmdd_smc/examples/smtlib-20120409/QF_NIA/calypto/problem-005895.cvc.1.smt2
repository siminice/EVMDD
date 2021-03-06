(set-logic QF_NIA)
(set-info :source |
    Sequential equivalence checking.
    Calypto Design Systems, Inc. <www.calypto.com>
  |)
(set-info :smt-lib-version 2.0)
(set-info :category "industrial")
(set-info :status sat)
(declare-fun P_2 () Int)
(declare-fun P_3 () Int)
(declare-fun P_4 () Bool)
(declare-fun P_5 () Bool)
(assert (<= 0 P_2))
(assert (<= P_2 127))
(assert (<= 0 P_3))
(assert (<= P_3 127))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_0 (* P_2 P_3))) (= (+ (* 256 dz) rz) (- (ite (not (and (= (+ (ite P_4 128 0) P_2) 238) (= (+ (ite P_5 128 0) P_3) 17))) ?v_0 (- P_2 P_3)) ?v_0))))
(assert (> rz 0))
(assert (< rz 256))
(check-sat)
(exit)
