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
(declare-fun P_25 () Int)
(assert (<= 0 P_2))
(assert (<= P_2 15))
(assert (<= 0 P_3))
(assert (<= P_3 15))
(assert (<= 0 P_4))
(assert (<= P_4 15))
(assert (<= 0 P_5))
(assert (<= P_5 15))
(assert (<= 0 P_6))
(assert (<= P_6 15))
(assert (<= 0 P_7))
(assert (<= P_7 15))
(assert (<= 0 P_8))
(assert (<= P_8 15))
(assert (<= 0 P_9))
(assert (<= P_9 15))
(assert (<= 0 P_10))
(assert (<= P_10 15))
(assert (<= 0 P_11))
(assert (<= P_11 15))
(assert (<= 0 P_12))
(assert (<= P_12 15))
(assert (<= 0 P_13))
(assert (<= P_13 15))
(assert (<= 0 P_14))
(assert (<= P_14 15))
(assert (<= 0 P_15))
(assert (<= P_15 15))
(assert (<= 0 P_16))
(assert (<= P_16 15))
(assert (<= 0 P_17))
(assert (<= P_17 15))
(assert (<= 0 P_18))
(assert (<= P_18 15))
(assert (<= 0 P_19))
(assert (<= P_19 15))
(assert (<= 0 P_20))
(assert (<= P_20 15))
(assert (<= 0 P_21))
(assert (<= P_21 15))
(assert (<= 0 P_22))
(assert (<= P_22 15))
(assert (<= 0 P_23))
(assert (<= P_23 15))
(assert (<= 0 P_24))
(assert (<= P_24 15))
(assert (<= 0 P_25))
(assert (<= P_25 15))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_0 (* P_2 P_3))) (let ((?v_1 (+ (+ ?v_0 (* P_4 ?v_0)) (* P_5 P_6)))) (let ((?v_2 (+ (+ ?v_1 (* P_7 ?v_1)) (* P_8 P_9)))) (let ((?v_3 (+ (+ ?v_2 (* P_10 ?v_2)) (* P_11 P_12)))) (let ((?v_4 (+ (+ ?v_3 (* P_13 ?v_3)) (* P_14 P_15)))) (let ((?v_5 (+ (+ ?v_4 (* P_16 ?v_4)) (* P_17 P_18)))) (let ((?v_6 (+ (+ ?v_5 (* P_19 ?v_5)) (* P_20 P_21)))) (let ((?v_7 (+ (+ ?v_6 (* P_22 ?v_6)) (* P_23 P_24)))) (= (+ (* 4096 dz) rz) (- (+ ?v_7 (* P_25 ?v_7)) 0)))))))))))
(assert (> rz 0))
(assert (< rz 4096))
(check-sat)
(exit)
