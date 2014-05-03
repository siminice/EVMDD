(set-logic QF_NIA)
(set-info :source |
    Sequential equivalence checking.
    Calypto Design Systems, Inc. <www.calypto.com>
  |)
(set-info :smt-lib-version 2.0)
(set-info :category "industrial")
(set-info :status unsat)
(declare-fun P_2 () Int)
(declare-fun P_3 () Bool)
(declare-fun P_4 () Int)
(declare-fun P_5 () Int)
(declare-fun P_6 () Int)
(declare-fun P_7 () Int)
(declare-fun P_8 () Int)
(declare-fun P_9 () Int)
(declare-fun P_10 () Int)
(declare-fun P_11 () Int)
(assert (<= 0 P_2))
(assert (<= P_2 255))
(assert (<= 0 P_4))
(assert (<= P_4 255))
(assert (<= 0 P_5))
(assert (<= P_5 255))
(assert (<= 0 P_6))
(assert (<= P_6 255))
(assert (<= 0 P_7))
(assert (<= P_7 32767))
(assert (<= 0 P_8))
(assert (<= P_8 32767))
(assert (<= 0 P_9))
(assert (<= P_9 511))
(assert (<= 0 P_10))
(assert (<= P_10 32767))
(assert (<= 0 P_11))
(assert (<= P_11 32767))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_1 (not P_3))) (let ((?v_0 (ite ?v_1 P_4 P_5))) (let ((?v_2 (not (and (> P_2 ?v_0) (<= P_2 (+ P_6 ?v_0))))) (?v_4 (ite ?v_1 P_10 P_11)) (?v_3 (ite ?v_1 P_7 P_8))) (= (+ (* 16777216 dz) rz) (- (* P_9 (ite (not ?v_2) ?v_4 ?v_3)) (ite ?v_2 (* ?v_3 P_9) (* ?v_4 P_9))))))))
(assert (> rz 0))
(assert (< rz 16777216))
(check-sat)
(exit)
