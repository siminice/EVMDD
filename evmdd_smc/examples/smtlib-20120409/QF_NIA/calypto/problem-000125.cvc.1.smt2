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
(declare-fun P_7 () Bool)
(declare-fun P_8 () Int)
(declare-fun P_9 () Int)
(declare-fun P_10 () Int)
(declare-fun mux_I_114299 () Int)
(declare-fun mux_I_114327 () Int)
(declare-fun mux_I_114305 () Int)
(assert (<= 0 P_2))
(assert (<= P_2 3))
(assert (<= 0 P_3))
(assert (<= P_3 3))
(assert (<= 0 P_4))
(assert (<= P_4 43))
(assert (<= 0 P_5))
(assert (<= P_5 2818572864))
(assert (<= 0 P_6))
(assert (<= P_6 3848290795520))
(assert (<= 0 P_8))
(assert (<= P_8 15))
(assert (<= 0 P_9))
(assert (<= P_9 15))
(assert (<= 0 P_10))
(assert (<= P_10 58720268))
(assert (<= 0 mux_I_114299))
(assert (<= mux_I_114299 4398046511103))
(assert (<= 0 mux_I_114327))
(assert (<= mux_I_114327 4294967295))
(assert (<= 0 mux_I_114305))
(assert (<= mux_I_114305 15))
(declare-fun dz () Int)
(declare-fun rz () Bool)
(assert (let ((?v_0 (+ (ite P_7 16 0) P_8))) (let ((?v_1 (< (+ (+ (+ (+ (+ (+ 536870912 (+ (* P_2 134217728) (* P_3 64))) mux_I_114327) (- (* 1 (- 1)) P_6)) 1) (+ (* (* (ite (< ?v_0 16) ?v_0 (- ?v_0 32)) (+ 8388608 (+ (* P_2 2097152) P_3))) 4) 0)) (* mux_I_114305 P_10)) 0))) (= (+ (* 2 dz) 1) (- (ite (and (not (= mux_I_114299 0)) ?v_1) 1 0) (ite ?v_1 1 0))))))
(check-sat)
(exit)
