(set-logic QF_NIA)
(set-info :source |
    Sequential equivalence checking.
    Calypto Design Systems, Inc. <www.calypto.com>
  |)
(set-info :smt-lib-version 2.0)
(set-info :category "industrial")
(set-info :status unsat)
(declare-fun P_2 () Bool)
(declare-fun P_3 () Bool)
(declare-fun P_4 () Bool)
(declare-fun P_5 () Bool)
(declare-fun P_6 () Bool)
(declare-fun P_7 () Bool)
(declare-fun P_8 () Bool)
(declare-fun P_9 () Bool)
(declare-fun P_10 () Bool)
(declare-fun P_11 () Bool)
(declare-fun P_12 () Bool)
(declare-fun P_13 () Bool)
(declare-fun P_14 () Bool)
(declare-fun P_15 () Bool)
(declare-fun P_16 () Bool)
(declare-fun P_17 () Int)
(declare-fun P_18 () Int)
(declare-fun P_19 () Int)
(declare-fun P_20 () Int)
(declare-fun P_33 () Int)
(declare-fun P_34 () Int)
(declare-fun P_35 () Int)
(declare-fun P_36 () Int)
(declare-fun P_37 () Int)
(declare-fun P_38 () Int)
(declare-fun P_39 () Int)
(declare-fun P_40 () Int)
(declare-fun P_41 () Int)
(declare-fun P_42 () Int)
(declare-fun P_43 () Int)
(declare-fun P_44 () Int)
(assert (<= 0 P_17))
(assert (<= P_17 255))
(assert (<= 0 P_18))
(assert (<= P_18 255))
(assert (<= 0 P_19))
(assert (<= P_19 255))
(assert (<= 0 P_20))
(assert (<= P_20 255))
(assert (<= 0 P_33))
(assert (<= P_33 255))
(assert (<= 0 P_34))
(assert (<= P_34 255))
(assert (<= 0 P_35))
(assert (<= P_35 255))
(assert (<= 0 P_36))
(assert (<= P_36 255))
(assert (<= 0 P_37))
(assert (<= P_37 255))
(assert (<= 0 P_38))
(assert (<= P_38 255))
(assert (<= 0 P_39))
(assert (<= P_39 255))
(assert (<= 0 P_40))
(assert (<= P_40 255))
(assert (<= 0 P_41))
(assert (<= P_41 255))
(assert (<= 0 P_42))
(assert (<= P_42 255))
(assert (<= 0 P_43))
(assert (<= P_43 255))
(assert (<= 0 P_44))
(assert (<= P_44 255))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_14 (not P_16)) (?v_13 (not P_15)) (?v_12 (not P_14)) (?v_11 (not P_13)) (?v_10 (not P_12)) (?v_9 (not P_11)) (?v_8 (not P_10)) (?v_7 (not P_9)) (?v_6 (not P_8)) (?v_5 (not P_7)) (?v_4 (not P_6)) (?v_3 (not P_5)) (?v_2 (not P_4)) (?v_1 (not P_3)) (?v_0 (not P_2))) (= (+ (* 256 dz) rz) (- (ite ?v_0 (ite ?v_1 (ite ?v_2 (ite ?v_3 (ite ?v_4 (ite ?v_5 (ite ?v_6 (ite ?v_7 (ite ?v_8 (ite ?v_9 (ite ?v_10 (ite ?v_11 (ite ?v_12 (ite ?v_13 (ite ?v_14 (* (+ (ite ?v_0 (ite ?v_1 (ite ?v_2 (ite ?v_3 (ite ?v_4 (ite ?v_5 (ite ?v_6 (ite ?v_7 (ite ?v_8 (ite ?v_9 (ite ?v_10 (ite ?v_11 (ite ?v_12 (ite ?v_13 (ite ?v_14 P_17 P_33) P_34) P_35) P_36) P_37) P_38) P_38) P_39) P_40) P_41) P_42) P_43) P_20) P_19) P_18) (ite ?v_0 (ite ?v_1 (ite ?v_2 (ite ?v_3 (ite ?v_4 (ite ?v_5 (ite ?v_6 (ite ?v_7 (ite ?v_8 (ite ?v_9 (ite ?v_10 (ite ?v_11 (ite ?v_12 (ite ?v_13 (ite ?v_14 P_18 P_17) P_33) P_34) P_35) P_36) P_37) P_37) P_44) P_39) P_40) P_41) P_42) P_43) P_20) P_19)) (- (ite ?v_0 (ite ?v_1 (ite ?v_2 (ite ?v_3 (ite ?v_4 (ite ?v_5 (ite ?v_6 (ite ?v_7 (ite ?v_8 (ite ?v_9 (ite ?v_10 (ite ?v_11 (ite ?v_12 (ite ?v_13 (ite ?v_14 P_19 P_18) P_17) P_33) P_34) P_35) P_36) P_36) P_38) P_44) P_39) P_40) P_41) P_42) P_43) P_20) (ite ?v_0 (ite ?v_1 (ite ?v_2 (ite ?v_3 (ite ?v_4 (ite ?v_5 (ite ?v_6 (ite ?v_7 (ite ?v_8 (ite ?v_9 (ite ?v_10 (ite ?v_11 (ite ?v_12 (ite ?v_13 (ite ?v_14 P_20 P_19) P_18) P_17) P_33) P_34) P_35) P_35) P_37) P_38) P_44) P_39) P_40) P_41) P_42) P_43))) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0) (ite ?v_0 (ite ?v_1 (ite ?v_2 (ite ?v_3 (ite ?v_4 (ite ?v_5 (ite ?v_6 (ite ?v_7 (ite ?v_8 (ite ?v_9 (ite ?v_10 (ite ?v_11 (ite ?v_12 (ite ?v_13 (ite ?v_14 (* (+ P_17 P_18) (- P_19 P_20)) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0) 0)))))
(assert (> rz 0))
(assert (< rz 256))
(check-sat)
(exit)
