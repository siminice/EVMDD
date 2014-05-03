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
(assert (<= 0 P_2))
(assert (<= P_2 255))
(assert (<= 0 P_3))
(assert (<= P_3 255))
(assert (<= 0 P_4))
(assert (<= P_4 255))
(assert (<= 0 P_5))
(assert (<= P_5 255))
(assert (<= 0 P_6))
(assert (<= P_6 255))
(assert (<= 0 P_7))
(assert (<= P_7 255))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_0 (+ (+ (* (ite (< P_2 128) P_2 (- P_2 256)) (ite (< P_3 128) P_3 (- P_3 256))) (* (ite (< P_4 128) P_4 (- P_4 256)) (ite (< P_5 128) P_5 (- P_5 256)))) (* (ite (< P_6 128) P_6 (- P_6 256)) (ite (< P_7 128) P_7 (- P_7 256)))))) (let ((?v_1 (+ (ite (< ?v_0 0) 549755813888 0) (ite (>= ?v_0 0) ?v_0 (+ ?v_0 549755813888))))) (= (+ (* 2199023255552 dz) rz) (- (ite (< ?v_1 549755813888) ?v_1 (- ?v_1 1099511627776)) ?v_0)))))
(assert (> rz 0))
(assert (< rz 2199023255552))
(check-sat)
(exit)