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
(declare-fun P_4 () Int)
(declare-fun P_5 () Int)
(declare-fun P_6 () Int)
(declare-fun P_7 () Int)
(declare-fun P_8 () Int)
(declare-fun P_9 () Bool)
(declare-fun P_10 () Int)
(assert (<= 0 P_2))
(assert (<= P_2 43))
(assert (<= 0 P_3))
(assert (<= P_3 1073741760))
(assert (<= 0 P_4))
(assert (<= P_4 3))
(assert (<= 0 P_5))
(assert (<= P_5 3))
(assert (<= 0 P_6))
(assert (<= P_6 3848290795520))
(assert (<= 0 P_7))
(assert (<= P_7 15))
(assert (<= 0 P_8))
(assert (<= P_8 67108860))
(assert (<= 0 P_10))
(assert (<= P_10 15))
(declare-fun dz () Int)
(declare-fun rz () Bool)
(assert (let ((?v_2 (+ 8388608 (+ (* P_4 2097152) P_5))) (?v_1 (+ (ite P_9 16 0) P_10)) (?v_0 (not (= P_2 43)))) (let ((?v_3 (+ (+ (+ (+ (ite ?v_0 P_3 0) (* (* ?v_2 (* 3 (- 1))) 64)) P_6) (* (ite ?v_0 (- P_7) 0) P_8)) (+ (* (* (ite (< ?v_1 16) ?v_1 (- ?v_1 32)) ?v_2) 4) 0)))) (let ((?v_5 (< ?v_3 0)) (?v_4 (- (* 1 (- 1)) (- ?v_3 (* 8589934592 (- 1)))))) (= (+ (* 2 dz) 1) (- (ite (and (not (= (ite (not ?v_5) ?v_3 (ite (>= ?v_4 0) ?v_4 (+ ?v_4 8589934592))) 0)) ?v_5) 1 0) (ite ?v_5 1 0)))))))
(check-sat)
(exit)
