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
(declare-fun P_7 () Int)
(declare-fun P_8 () Int)
(declare-fun P_9 () Int)
(assert (<= 0 P_2))
(assert (<= P_2 43))
(assert (<= 0 P_3))
(assert (<= P_3 1073741760))
(assert (<= 0 P_4))
(assert (<= P_4 3))
(assert (<= 0 P_5))
(assert (<= P_5 3))
(assert (<= 0 P_6))
(assert (<= P_6 4398046478336))
(assert (<= 0 P_7))
(assert (<= P_7 15))
(assert (<= 0 P_8))
(assert (<= P_8 67108860))
(assert (<= 0 P_9))
(assert (<= P_9 15))
(declare-fun dz () Int)
(declare-fun rz () Bool)
(assert (let ((?v_1 (+ 8388608 (+ (* P_4 2097152) P_5))) (?v_0 (not (= P_2 43))) (?v_3 (* 1 (- 1)))) (let ((?v_2 (+ (+ (+ (+ (+ (ite ?v_0 P_3 0) (* (* ?v_1 3) 64)) (- ?v_3 P_6)) 1) (* (ite ?v_0 (- P_7) 0) P_8)) (* (* P_9 ?v_1) 4)))) (let ((?v_4 (< ?v_2 0))) (= (+ (* 2 dz) 1) (- (ite (and (not (= (ite (not ?v_4) ?v_2 (- ?v_3 (- ?v_2 (* 4398046511104 (- 1))))) 0)) ?v_4) 1 0) (ite ?v_4 1 0)))))))
(check-sat)
(exit)
