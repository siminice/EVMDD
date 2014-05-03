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
(declare-fun mux_I_97442 () Int)
(declare-fun mux_I_97469 () Int)
(declare-fun mux_I_97452 () Int)
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
(assert (<= 0 mux_I_97442))
(assert (<= mux_I_97442 4398046511103))
(assert (<= 0 mux_I_97469))
(assert (<= mux_I_97469 1073741823))
(assert (<= (* 16 (- 1)) mux_I_97452))
(assert (<= mux_I_97452 15))
(declare-fun dz () Int)
(declare-fun rz () Bool)
(assert (let ((?v_0 (+ 8388608 (+ (* P_4 2097152) P_5)))) (let ((?v_1 (< (+ (+ (+ (+ (+ mux_I_97469 (* (* ?v_0 3) 64)) (- (* 1 (- 1)) P_6)) 1) (* mux_I_97452 P_8)) (* (* P_9 ?v_0) 4)) 0))) (= (+ (* 2 dz) 1) (- (ite (and (not (= mux_I_97442 0)) ?v_1) 1 0) (ite ?v_1 1 0))))))
(check-sat)
(exit)
