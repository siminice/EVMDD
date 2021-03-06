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
(declare-fun P_10 () Int)
(declare-fun P_11 () Int)
(declare-fun mux_I_112044 () Int)
(declare-fun mux_I_112040 () Int)
(declare-fun mux_I_112023 () Int)
(declare-fun mux_I_112019 () Int)
(assert (<= 0 P_2))
(assert (<= P_2 43))
(assert (<= 0 P_3))
(assert (<= P_3 1073741760))
(assert (<= 0 P_4))
(assert (<= P_4 43))
(assert (<= 0 P_5))
(assert (<= P_5 2818572864))
(assert (<= 0 P_6))
(assert (<= P_6 3))
(assert (<= 0 P_7))
(assert (<= P_7 3))
(assert (<= 0 P_8))
(assert (<= P_8 15))
(assert (<= 0 P_9))
(assert (<= P_9 67108860))
(assert (<= 0 P_10))
(assert (<= P_10 15))
(assert (<= 0 P_11))
(assert (<= P_11 58720268))
(assert (<= 0 mux_I_112044))
(assert (<= mux_I_112044 1073741823))
(assert (<= 0 mux_I_112040))
(assert (<= mux_I_112040 4294967295))
(assert (<= (* 16 (- 1)) mux_I_112023))
(assert (<= mux_I_112023 15))
(assert (<= 0 mux_I_112019))
(assert (<= mux_I_112019 15))
(declare-fun dz () Int)
(declare-fun rz () Bool)
(assert (let ((?v_0 (+ 131072 (* P_7 32768)))) (let ((?v_1 (ite (< ?v_0 131072) ?v_0 (- ?v_0 262144)))) (let ((?v_3 (+ 2199023255552 (+ (* P_6 549755813888) (ite (>= ?v_1 0) ?v_1 (+ ?v_1 549755813888)))))) (let ((?v_2 (+ (+ (+ (+ mux_I_112044 mux_I_112040) ?v_3) (* mux_I_112023 P_9)) (* mux_I_112019 P_11))) (?v_4 (not (= P_2 43))) (?v_5 (not (= P_4 43)))) (let ((?v_6 (+ (+ (+ (+ (ite ?v_4 P_3 0) (ite ?v_5 P_5 0)) ?v_3) (* (ite ?v_4 (- P_8) 0) P_9)) (* (ite ?v_5 P_10 0) P_11)))) (= (+ (* 2 dz) 1) (- (ite (< (ite (< ?v_2 4398046511104) ?v_2 (- ?v_2 8796093022208)) 0) 1 0) (ite (not (and (< (- ?v_6 4398046511104) 0) (not (< (ite (< ?v_6 4398046511104) ?v_6 (- ?v_6 8796093022208)) 0)))) 1 0)))))))))
(check-sat)
(exit)
