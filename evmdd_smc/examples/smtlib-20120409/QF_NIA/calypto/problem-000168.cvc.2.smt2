(set-logic QF_NIA)
(set-info :source |
    Sequential equivalence checking.
    Calypto Design Systems, Inc. <www.calypto.com>
  |)
(set-info :smt-lib-version 2.0)
(set-info :category "industrial")
(set-info :status unknown)
(declare-fun P_2 () Int)
(declare-fun P_3 () Int)
(declare-fun P_4 () Int)
(declare-fun P_5 () Int)
(declare-fun P_6 () Int)
(declare-fun P_7 () Bool)
(declare-fun P_8 () Int)
(declare-fun P_9 () Int)
(declare-fun P_10 () Int)
(assert (<= 0 P_2))
(assert (<= P_2 3))
(assert (<= 0 P_3))
(assert (<= P_3 3))
(assert (<= 0 P_4))
(assert (<= P_4 43))
(assert (<= 0 P_5))
(assert (<= P_5 3221225280))
(assert (<= 0 P_6))
(assert (<= P_6 3848290795520))
(assert (<= 0 P_8))
(assert (<= P_8 15))
(assert (<= 0 P_9))
(assert (<= P_9 15))
(assert (<= 0 P_10))
(assert (<= P_10 67108860))
(declare-fun dz () Int)
(declare-fun rz () Bool)
(assert (let ((?v_0 (+ 256 (* P_3 64)))) (let ((?v_1 (ite (< ?v_0 256) ?v_0 (- ?v_0 512))) (?v_2 (+ (ite P_7 16 0) P_8)) (?v_3 (+ 4 P_3))) (let ((?v_4 (ite (< ?v_3 4) ?v_3 (- ?v_3 8))) (?v_5 (not (= P_4 43))) (?v_7 (* 1 (- 1)))) (let ((?v_6 (+ (+ (+ (+ (+ (+ 536870912 (+ (* P_2 134217728) (ite (>= ?v_1 0) ?v_1 (+ ?v_1 134217728)))) (ite ?v_5 P_5 0)) (- ?v_7 P_6)) 1) (+ (* (* (ite (< ?v_2 16) ?v_2 (- ?v_2 32)) (+ 8388608 (+ (* P_2 2097152) (ite (>= ?v_4 0) ?v_4 (+ ?v_4 2097152))))) 4) 0)) (* (ite ?v_5 P_9 0) P_10)))) (let ((?v_8 (< ?v_6 0))) (= (+ (* 2 dz) 1) (- (ite (and (not (= (ite (not ?v_8) ?v_6 (- ?v_7 (- ?v_6 (* 4398046511104 (- 1))))) 0)) ?v_8) 1 0) (ite ?v_8 1 0)))))))))
(check-sat)
(exit)
