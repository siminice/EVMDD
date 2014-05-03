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
(declare-fun P_4 () Int)
(declare-fun P_5 () Int)
(declare-fun P_6 () Int)
(declare-fun P_7 () Int)
(declare-fun P_8 () Int)
(declare-fun P_9 () Bool)
(declare-fun P_10 () Int)
(declare-fun P_11 () Int)
(declare-fun P_12 () Int)
(declare-fun P_13 () Int)
(declare-fun P_14 () Int)
(declare-fun P_15 () Int)
(declare-fun P_16 () Int)
(declare-fun P_17 () Int)
(declare-fun P_18 () Int)
(declare-fun P_19 () Int)
(declare-fun P_20 () Int)
(declare-fun P_21 () Int)
(declare-fun P_22 () Int)
(declare-fun P_23 () Int)
(declare-fun P_24 () Int)
(declare-fun P_28 () Int)
(declare-fun P_29 () Int)
(assert (<= 0 P_4))
(assert (<= P_4 255))
(assert (<= 0 P_5))
(assert (<= P_5 255))
(assert (<= 0 P_6))
(assert (<= P_6 255))
(assert (<= 0 P_7))
(assert (<= P_7 255))
(assert (<= 0 P_8))
(assert (<= P_8 3))
(assert (<= 0 P_10))
(assert (<= P_10 255))
(assert (<= 0 P_11))
(assert (<= P_11 255))
(assert (<= 0 P_12))
(assert (<= P_12 255))
(assert (<= 0 P_13))
(assert (<= P_13 255))
(assert (<= 0 P_14))
(assert (<= P_14 255))
(assert (<= 0 P_15))
(assert (<= P_15 255))
(assert (<= 0 P_16))
(assert (<= P_16 255))
(assert (<= 0 P_17))
(assert (<= P_17 3))
(assert (<= 0 P_18))
(assert (<= P_18 255))
(assert (<= 0 P_19))
(assert (<= P_19 255))
(assert (<= 0 P_20))
(assert (<= P_20 255))
(assert (<= 0 P_21))
(assert (<= P_21 255))
(assert (<= 0 P_22))
(assert (<= P_22 255))
(assert (<= 0 P_23))
(assert (<= P_23 255))
(assert (<= 0 P_24))
(assert (<= P_24 255))
(assert (<= 0 P_28))
(assert (<= P_28 3))
(assert (<= 0 P_29))
(assert (<= P_29 255))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_1 (ite (not P_2) (ite (not P_3) 2 1) 0)) (?v_2 (- (* P_4 P_5) P_6)) (?v_3 (not P_9))) (let ((?v_4 (- (ite ?v_3 P_10 P_11) (ite ?v_3 P_12 P_13))) (?v_5 (- P_11 P_13)) (?v_14 (= P_17 2)) (?v_13 (= P_17 1)) (?v_12 (= P_17 0))) (let ((?v_19 (ite ?v_12 ?v_5 (ite ?v_13 ?v_5 (ite ?v_14 (- P_14 P_16) P_18)))) (?v_11 (= P_8 2)) (?v_9 (= P_8 1)) (?v_8 (= P_8 0))) (let ((?v_16 (ite ?v_8 ?v_4 (ite ?v_9 ?v_4 (ite ?v_11 (- (ite ?v_3 P_12 P_14) (ite ?v_3 P_15 P_16)) ?v_19)))) (?v_7 (= ?v_1 2)) (?v_6 (= ?v_1 1)) (?v_0 (= ?v_1 0)) (?v_10 (ite ?v_3 P_15 P_20)) (?v_20 (ite ?v_12 P_20 (ite ?v_13 P_20 (ite ?v_14 P_23 P_24))))) (let ((?v_17 (ite ?v_8 ?v_10 (ite ?v_9 ?v_10 (ite ?v_11 (ite ?v_3 (- P_21 P_22) P_23) ?v_20))))) (let ((?v_15 (+ (ite ?v_0 ?v_2 (ite ?v_6 ?v_2 (ite ?v_7 (- P_6 P_7) ?v_16))) (ite ?v_0 P_7 (ite ?v_6 P_7 (ite ?v_7 P_19 ?v_17))))) (?v_18 (+ ?v_16 ?v_17)) (?v_21 (+ ?v_19 ?v_20)) (?v_22 (+ P_18 P_24))) (= (+ (* 256 dz) rz) (- (ite ?v_0 ?v_15 (ite ?v_6 ?v_15 (ite ?v_7 ?v_15 (ite ?v_8 ?v_18 (ite ?v_9 ?v_18 (ite ?v_11 ?v_18 (ite ?v_12 ?v_21 (ite ?v_13 ?v_21 (ite ?v_14 ?v_21 (ite (= P_28 0) ?v_22 (ite (= P_28 1) ?v_22 (ite (= P_28 2) ?v_22 P_29)))))))))))) ?v_15)))))))))
(assert (> rz 0))
(assert (< rz 256))
(check-sat)
(exit)
