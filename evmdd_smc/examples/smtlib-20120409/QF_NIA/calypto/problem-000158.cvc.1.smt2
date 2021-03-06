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
(declare-fun P_9 () Int)
(declare-fun mux_I_129527 () Int)
(declare-fun mux_I_129544 () Int)
(declare-fun mux_I_129533 () Int)
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
(assert (<= 0 P_7))
(assert (<= P_7 15))
(assert (<= 0 P_8))
(assert (<= P_8 15))
(assert (<= 0 P_9))
(assert (<= P_9 58720268))
(assert (<= 0 mux_I_129527))
(assert (<= mux_I_129527 4398046511103))
(assert (<= 0 mux_I_129544))
(assert (<= mux_I_129544 4294967295))
(assert (<= 0 mux_I_129533))
(assert (<= mux_I_129533 15))
(declare-fun dz () Int)
(declare-fun rz () Bool)
(assert (let ((?v_0 (+ 4 P_3))) (let ((?v_1 (ite (< ?v_0 4) ?v_0 (- ?v_0 8)))) (let ((?v_2 (+ 8388608 (+ (* P_2 2097152) (ite (>= ?v_1 0) ?v_1 (+ ?v_1 2097152)))))) (let ((?v_3 (< (+ (+ (+ (+ (+ (+ (* (- ?v_2) 64) 0) mux_I_129544) (- (* 1 (- 1)) P_6)) 1) (* (* P_7 ?v_2) 4)) (* mux_I_129533 P_9)) 0))) (= (+ (* 2 dz) 1) (- (ite (and (not (= mux_I_129527 0)) ?v_3) 1 0) (ite ?v_3 1 0))))))))
(check-sat)
(exit)
