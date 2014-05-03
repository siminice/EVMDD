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
(assert (<= 0 P_2))
(assert (<= P_2 65535))
(assert (<= 0 P_3))
(assert (<= P_3 65535))
(assert (<= 0 P_4))
(assert (<= P_4 65535))
(assert (<= 0 P_5))
(assert (<= P_5 65535))
(declare-fun dz () Int)
(declare-fun rz () Bool)
(assert (let ((?v_0 (* (ite (< P_2 32768) P_2 (- P_2 65536)) (ite (< P_3 32768) P_3 (- P_3 65536)))) (?v_1 (* (ite (< P_4 32768) P_4 (- P_4 65536)) (ite (< P_5 32768) P_5 (- P_5 65536))))) (= (+ (* 2 dz) 1) (- (ite (and (and (not (< ?v_0 0)) (< ?v_1 0)) (< (- ?v_0 ?v_1) 0)) 1 0) 0))))
(check-sat)
(exit)
