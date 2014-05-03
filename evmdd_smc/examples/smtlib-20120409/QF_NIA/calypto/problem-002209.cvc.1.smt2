(set-logic QF_NIA)
(set-info :source |
    Sequential equivalence checking.
    Calypto Design Systems, Inc. <www.calypto.com>
  |)
(set-info :smt-lib-version 2.0)
(set-info :category "industrial")
(set-info :status unsat)
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
(assert (<= 0 P_2))
(assert (<= P_2 255))
(assert (<= (* 128 (- 1)) P_3))
(assert (<= P_3 127))
(assert (<= 0 P_4))
(assert (<= P_4 255))
(assert (<= (* 128 (- 1)) P_5))
(assert (<= P_5 127))
(assert (<= 0 P_6))
(assert (<= P_6 255))
(assert (<= (* 128 (- 1)) P_7))
(assert (<= P_7 127))
(assert (<= 0 P_8))
(assert (<= P_8 255))
(assert (<= (* 128 (- 1)) P_9))
(assert (<= P_9 127))
(assert (<= 0 P_10))
(assert (<= P_10 255))
(assert (<= (* 128 (- 1)) P_11))
(assert (<= P_11 127))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_2 (+ (* (ite (< P_6 128) P_6 (- P_6 256)) P_7) (* (ite (< P_8 128) P_8 (- P_8 256)) P_9))) (?v_0 (* (ite (< P_2 128) P_2 (- P_2 256)) P_3)) (?v_1 (* (ite (< P_4 128) P_4 (- P_4 256)) P_5)) (?v_3 (* (ite (< P_10 128) P_10 (- P_10 256)) P_11))) (= (+ (* 65536 dz) rz) (- (+ (+ (+ ?v_2 ?v_0) ?v_1) ?v_3) (+ (+ (+ ?v_0 ?v_1) ?v_2) ?v_3)))))
(assert (> rz 0))
(assert (< rz 65536))
(check-sat)
(exit)
