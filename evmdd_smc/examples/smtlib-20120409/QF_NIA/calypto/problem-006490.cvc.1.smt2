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
(assert (<= (* 32768 (- 1)) P_2))
(assert (<= P_2 32767))
(assert (<= (* 32768 (- 1)) P_3))
(assert (<= P_3 32767))
(assert (<= (* 128 (- 1)) P_4))
(assert (<= P_4 127))
(assert (<= 0 P_5))
(assert (<= P_5 255))
(declare-fun dz () Int)
(declare-fun rz () Int)
(assert (let ((?v_0 (+ (+ P_2 P_3) (* P_4 (ite (< P_5 128) P_5 (- P_5 256)))))) (let ((?v_1 (+ (ite (< ?v_0 0) 549755813888 0) (ite (>= ?v_0 0) ?v_0 (+ ?v_0 549755813888))))) (= (+ (* 2199023255552 dz) rz) (- (ite (< ?v_1 549755813888) ?v_1 (- ?v_1 1099511627776)) ?v_0)))))
(assert (> rz 0))
(assert (< rz 2199023255552))
(check-sat)
(exit)
