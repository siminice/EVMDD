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
(declare-fun rz () Int)
(assert (let ((?v_1 (ite (< P_2 32768) P_2 (- P_2 65536))) (?v_0 (ite (< P_4 32768) P_4 (- P_4 65536))) (?v_2 (+ (* P_2 65536) P_3)) (?v_3 (+ (* P_4 65536) P_5))) (= (+ (* 18446744073709551616 dz) rz) (- (+ (+ (* (* ?v_1 ?v_0) 4294967296) (* P_3 P_5)) (+ (* (+ (* P_3 ?v_0) (* ?v_1 P_5)) 65536) 0)) (* (ite (< ?v_2 2147483648) ?v_2 (- ?v_2 4294967296)) (ite (< ?v_3 2147483648) ?v_3 (- ?v_3 4294967296)))))))
(assert (> rz 0))
(assert (< rz 18446744073709551616))
(check-sat)
(exit)
