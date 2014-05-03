(set-logic QF_NIA)
(set-info :source |
     Constraint systems stating that a matrix interpretation is
     compatible with a rewriting system (weakly compatible with
     all rules, strictly compatible with at least one).

     Contributed by Johannes Waldmann at HTKW Leipzig.
   |)
(set-info :smt-lib-version 2.0)
(set-info :category "crafted")
(set-info :status sat)
(declare-fun n0 () Int)
(assert (>= n0 0))
(declare-fun n1 () Int)
(assert (>= n1 0))
(declare-fun n2 () Int)
(assert (>= n2 0))
(declare-fun n3 () Int)
(assert (>= n3 0))
(declare-fun n4 () Int)
(assert (>= n4 0))
(declare-fun n5 () Int)
(assert (>= n5 0))
(declare-fun n6 () Int)
(assert (>= n6 0))
(declare-fun n7 () Int)
(assert (>= n7 0))
(declare-fun n8 () Int)
(assert (>= n8 0))
(declare-fun n9 () Int)
(assert (>= n9 0))
(declare-fun n10 () Int)
(assert (>= n10 0))
(declare-fun n11 () Int)
(assert (>= n11 0))
(declare-fun n12 () Int)
(assert (>= n12 0))
(declare-fun n13 () Int)
(assert (>= n13 0))
(declare-fun n14 () Int)
(assert (>= n14 0))
(declare-fun n15 () Int)
(assert (>= n15 0))
(declare-fun n16 () Int)
(assert (>= n16 0))
(declare-fun n17 () Int)
(assert (>= n17 0))
(declare-fun n18 () Int)
(assert (>= n18 0))
(declare-fun n19 () Int)
(assert (>= n19 0))
(declare-fun n20 () Int)
(assert (>= n20 0))
(declare-fun n21 () Int)
(assert (>= n21 0))
(declare-fun n22 () Int)
(assert (>= n22 0))
(declare-fun n23 () Int)
(assert (>= n23 0))
(declare-fun n24 () Int)
(assert (>= n24 0))
(declare-fun n25 () Int)
(assert (>= n25 0))
(declare-fun n26 () Int)
(assert (>= n26 0))
(declare-fun n27 () Int)
(assert (>= n27 0))
(declare-fun n28 () Int)
(assert (>= n28 0))
(declare-fun n29 () Int)
(assert (>= n29 0))
(declare-fun n30 () Int)
(assert (>= n30 0))
(declare-fun n31 () Int)
(assert (>= n31 0))
(declare-fun n32 () Int)
(assert (= n32 (* n25 n26)))
(declare-fun n33 () Int)
(assert (= n33 (+ n24 n32)))
(declare-fun n34 () Int)
(assert (= n34 (* n25 n27)))
(declare-fun n35 () Int)
(assert (= n35 (* n27 n26)))
(declare-fun n36 () Int)
(assert (= n36 (+ n26 n35)))
(declare-fun n37 () Int)
(assert (= n37 (* n27 n27)))
(declare-fun n38 () Int)
(assert (= n38 (* n34 n33)))
(declare-fun n39 () Int)
(assert (= n39 (+ n33 n38)))
(declare-fun n40 () Int)
(assert (= n40 (* n34 n34)))
(declare-fun n41 () Int)
(assert (= n41 (* n25 n33)))
(declare-fun n42 () Int)
(assert (= n42 (+ n24 n41)))
(declare-fun n43 () Int)
(assert (= n43 (* n25 n34)))
(declare-fun n44 () Int)
(assert (= n44 (* n9 n26)))
(declare-fun n45 () Int)
(assert (= n45 (+ n8 n44)))
(declare-fun n46 () Int)
(assert (= n46 (* n9 n27)))
(declare-fun n47 () Int)
(assert (= n47 (* n7 n26)))
(declare-fun n48 () Int)
(assert (= n48 (+ n6 n47)))
(declare-fun n49 () Int)
(assert (= n49 (* n7 n27)))
(declare-fun n50 () Int)
(assert (= n50 (* n34 n42)))
(declare-fun n51 () Int)
(assert (= n51 (+ n33 n50)))
(declare-fun n52 () Int)
(assert (= n52 (* n34 n43)))
(declare-fun n53 () Int)
(assert (= n53 (* n11 n26)))
(declare-fun n54 () Int)
(assert (= n54 (+ n10 n53)))
(declare-fun n55 () Int)
(assert (= n55 (* n11 n27)))
(declare-fun n56 () Int)
(assert (= n56 (* n17 n16)))
(declare-fun n57 () Int)
(assert (= n57 (+ n16 n56)))
(declare-fun n58 () Int)
(assert (= n58 (* n17 n17)))
(declare-fun n59 () Int)
(assert (= n59 (* n34 n26)))
(declare-fun n60 () Int)
(assert (= n60 (+ n33 n59)))
(declare-fun n61 () Int)
(assert (= n61 (* n34 n27)))
(declare-fun n62 () Int)
(assert (= n62 (* n19 n51)))
(declare-fun n63 () Int)
(assert (= n63 (+ n18 n62)))
(declare-fun n64 () Int)
(assert (= n64 (* n19 n52)))
(declare-fun n65 () Int)
(assert (= n65 (* n23 n26)))
(declare-fun n66 () Int)
(assert (= n66 (+ n22 n65)))
(declare-fun n67 () Int)
(assert (= n67 (* n23 n27)))
(declare-fun n68 () Int)
(assert (= n68 (* n67 n39)))
(declare-fun n69 () Int)
(assert (= n69 (+ n66 n68)))
(declare-fun n70 () Int)
(assert (= n70 (* n67 n40)))
(declare-fun n71 () Int)
(assert (= n71 (* n5 n26)))
(declare-fun n72 () Int)
(assert (= n72 (+ n4 n71)))
(declare-fun n73 () Int)
(assert (= n73 (* n5 n27)))
(declare-fun n74 () Int)
(assert (= n74 (* n17 n36)))
(declare-fun n75 () Int)
(assert (= n75 (+ n16 n74)))
(declare-fun n76 () Int)
(assert (= n76 (* n17 n37)))
(declare-fun n77 () Int)
(assert (= n77 (* n34 n63)))
(declare-fun n78 () Int)
(assert (= n78 (+ n33 n77)))
(declare-fun n79 () Int)
(assert (= n79 (* n34 n64)))
(declare-fun n80 () Int)
(assert (= n80 (* n37 n69)))
(declare-fun n81 () Int)
(assert (= n81 (+ n36 n80)))
(declare-fun n82 () Int)
(assert (= n82 (* n37 n70)))
(declare-fun n83 () Int)
(assert (= n83 (* n43 n26)))
(declare-fun n84 () Int)
(assert (= n84 (+ n42 n83)))
(declare-fun n85 () Int)
(assert (= n85 (* n43 n27)))
(declare-fun n86 () Int)
(assert (= n86 (* n21 n60)))
(declare-fun n87 () Int)
(assert (= n87 (+ n20 n86)))
(declare-fun n88 () Int)
(assert (= n88 (* n21 n61)))
(declare-fun n89 () Int)
(assert (= n89 (* n11 n33)))
(declare-fun n90 () Int)
(assert (= n90 (+ n10 n89)))
(declare-fun n91 () Int)
(assert (= n91 (* n11 n34)))
(declare-fun n92 () Int)
(assert (= n92 (* n11 n36)))
(declare-fun n93 () Int)
(assert (= n93 (+ n10 n92)))
(declare-fun n94 () Int)
(assert (= n94 (* n11 n37)))
(declare-fun n95 () Int)
(assert (= n95 (* n17 n26)))
(declare-fun n96 () Int)
(assert (= n96 (+ n16 n95)))
(declare-fun n97 () Int)
(assert (= n97 (* n17 n27)))
(declare-fun n98 () Int)
(assert (= n98 (* n97 n57)))
(declare-fun n99 () Int)
(assert (= n99 (+ n96 n98)))
(declare-fun n100 () Int)
(assert (= n100 (* n97 n58)))
(declare-fun n101 () Int)
(assert (= n101 (* n100 n57)))
(declare-fun n102 () Int)
(assert (= n102 (+ n99 n101)))
(declare-fun n103 () Int)
(assert (= n103 (* n100 n58)))
(declare-fun n104 () Int)
(assert (= n104 (* n103 n26)))
(declare-fun n105 () Int)
(assert (= n105 (+ n102 n104)))
(declare-fun n106 () Int)
(assert (= n106 (* n103 n27)))
(declare-fun n107 () Int)
(assert (= n107 (* n106 n16)))
(declare-fun n108 () Int)
(assert (= n108 (+ n105 n107)))
(declare-fun n109 () Int)
(assert (= n109 (* n106 n17)))
(declare-fun n110 () Int)
(assert (= n110 (* n27 n30)))
(declare-fun n111 () Int)
(assert (= n111 (+ n26 n110)))
(declare-fun n112 () Int)
(assert (= n112 (* n27 n31)))
(declare-fun n113 () Int)
(assert (= n113 (* n76 n30)))
(declare-fun n114 () Int)
(assert (= n114 (+ n75 n113)))
(declare-fun n115 () Int)
(assert (= n115 (* n76 n31)))
(declare-fun n116 () Int)
(assert (= n116 (* n94 n26)))
(declare-fun n117 () Int)
(assert (= n117 (+ n93 n116)))
(declare-fun n118 () Int)
(assert (= n118 (* n94 n27)))
(assert (>= n90 n10))
(assert (>= n91 n11))
(declare-fun n119 () Int)
(assert (= n119 (* n55 n87)))
(declare-fun n120 () Int)
(assert (= n120 (+ n54 n119)))
(declare-fun n121 () Int)
(assert (= n121 (* n55 n88)))
(assert (>= n72 n120))
(assert (>= n73 n121))
(declare-fun n122 () Int)
(assert (= n122 (* n7 n60)))
(declare-fun n123 () Int)
(assert (= n123 (+ n6 n122)))
(declare-fun n124 () Int)
(assert (= n124 (* n7 n61)))
(assert (>= n72 n123))
(assert (>= n73 n124))
(assert (>= n72 n93))
(assert (>= n73 n94))
(declare-fun n125 () Int)
(assert (= n125 (* n91 n81)))
(declare-fun n126 () Int)
(assert (= n126 (+ n90 n125)))
(declare-fun n127 () Int)
(assert (= n127 (* n91 n82)))
(assert (>= n48 n126))
(assert (>= n49 n127))
(declare-fun n128 () Int)
(assert (= n128 (* n118 n69)))
(declare-fun n129 () Int)
(assert (= n129 (+ n117 n128)))
(declare-fun n130 () Int)
(assert (= n130 (* n118 n70)))
(assert (>= n48 n129))
(assert (>= n49 n130))
(declare-fun n131 () Int)
(assert (= n131 (* n46 n39)))
(declare-fun n132 () Int)
(assert (= n132 (+ n45 n131)))
(declare-fun n133 () Int)
(assert (= n133 (* n46 n40)))
(assert (>= n48 n132))
(assert (>= n49 n133))
(declare-fun n134 () Int)
(assert (= n134 (* n55 n33)))
(declare-fun n135 () Int)
(assert (= n135 (+ n54 n134)))
(declare-fun n136 () Int)
(assert (= n136 (* n55 n34)))
(assert (>= n48 n135))
(assert (>= n49 n136))
(assert (>= n48 n54))
(assert (>= n49 n55))
(declare-fun n137 () Int)
(assert (= n137 (* n94 n78)))
(declare-fun n138 () Int)
(assert (= n138 (+ n93 n137)))
(declare-fun n139 () Int)
(assert (= n139 (* n94 n79)))
(assert (>= n45 n138))
(assert (>= n46 n139))
(declare-fun n140 () Int)
(assert (= n140 (* n55 n63)))
(declare-fun n141 () Int)
(assert (= n141 (+ n54 n140)))
(declare-fun n142 () Int)
(assert (= n142 (* n55 n64)))
(assert (>= n45 n141))
(assert (>= n46 n142))
(declare-fun n143 () Int)
(assert (= n143 (* n5 n51)))
(declare-fun n144 () Int)
(assert (= n144 (+ n4 n143)))
(declare-fun n145 () Int)
(assert (= n145 (* n5 n52)))
(assert (>= n45 n144))
(assert (>= n46 n145))
(declare-fun n146 () Int)
(assert (= n146 (* n55 n42)))
(declare-fun n147 () Int)
(assert (= n147 (+ n54 n146)))
(declare-fun n148 () Int)
(assert (= n148 (* n55 n43)))
(assert (>= n45 n147))
(assert (>= n46 n148))
(assert (>= n45 n90))
(assert (>= n46 n91))
(assert (>= n45 n54))
(assert (>= n46 n55))
(declare-fun n149 () Int)
(assert (= n149 (* n15 n16)))
(declare-fun n150 () Int)
(assert (= n150 (+ n14 n149)))
(declare-fun n151 () Int)
(assert (= n151 (* n15 n17)))
(declare-fun n152 () Int)
(assert (= n152 (* n15 n39)))
(declare-fun n153 () Int)
(assert (= n153 (+ n14 n152)))
(declare-fun n154 () Int)
(assert (= n154 (* n15 n40)))
(assert (>= n150 n153))
(assert (>= n151 n154))
(declare-fun n155 () Int)
(assert (= n155 (* n15 n36)))
(declare-fun n156 () Int)
(assert (= n156 (+ n14 n155)))
(declare-fun n157 () Int)
(assert (= n157 (* n15 n37)))
(declare-fun n158 () Int)
(assert (= n158 (* n15 n84)))
(declare-fun n159 () Int)
(assert (= n159 (+ n14 n158)))
(declare-fun n160 () Int)
(assert (= n160 (* n15 n85)))
(assert (>= n156 n159))
(assert (>= n157 n160))
(declare-fun n161 () Int)
(assert (= n161 (* n25 n16)))
(declare-fun n162 () Int)
(assert (= n162 (+ n24 n161)))
(declare-fun n163 () Int)
(assert (= n163 (* n25 n17)))
(declare-fun n164 () Int)
(assert (= n164 (* n76 n24)))
(declare-fun n165 () Int)
(assert (= n165 (+ n75 n164)))
(declare-fun n166 () Int)
(assert (= n166 (* n76 n25)))
(assert (>= n162 n165))
(assert (>= n163 n166))
(assert true)
(assert (>= n34 1))
(assert (>= n42 n24))
(assert (>= n43 n25))
(declare-fun n167 () Int)
(assert (= n167 (* n19 n26)))
(declare-fun n168 () Int)
(assert (= n168 (+ n18 n167)))
(declare-fun n169 () Int)
(assert (= n169 (* n19 n27)))
(declare-fun n170 () Int)
(assert (= n170 (* n34 n87)))
(declare-fun n171 () Int)
(assert (= n171 (+ n33 n170)))
(declare-fun n172 () Int)
(assert (= n172 (* n34 n88)))
(assert (>= n168 n171))
(assert (>= n169 n172))
(declare-fun n173 () Int)
(assert (= n173 (* n21 n26)))
(declare-fun n174 () Int)
(assert (= n174 (+ n20 n173)))
(declare-fun n175 () Int)
(assert (= n175 (* n21 n27)))
(declare-fun n176 () Int)
(assert (= n176 (* n43 n81)))
(declare-fun n177 () Int)
(assert (= n177 (+ n42 n176)))
(declare-fun n178 () Int)
(assert (= n178 (* n43 n82)))
(assert (>= n174 n177))
(assert (>= n175 n178))
(declare-fun n179 () Int)
(assert (= n179 (* n61 n78)))
(declare-fun n180 () Int)
(assert (= n180 (+ n60 n179)))
(declare-fun n181 () Int)
(assert (= n181 (* n61 n79)))
(assert (>= n66 n180))
(assert (>= n67 n181))
(declare-fun n182 () Int)
(assert (= n182 (* n31 n16)))
(declare-fun n183 () Int)
(assert (= n183 (+ n30 n182)))
(declare-fun n184 () Int)
(assert (= n184 (* n31 n17)))
(declare-fun n185 () Int)
(assert (= n185 (* n115 n39)))
(declare-fun n186 () Int)
(assert (= n186 (+ n114 n185)))
(declare-fun n187 () Int)
(assert (= n187 (* n115 n40)))
(assert (>= n183 n186))
(assert (>= n184 n187))
(declare-fun n188 () Int)
(assert (= n188 (* n31 n36)))
(declare-fun n189 () Int)
(assert (= n189 (+ n30 n188)))
(declare-fun n190 () Int)
(assert (= n190 (* n31 n37)))
(declare-fun n191 () Int)
(assert (= n191 (* n112 n84)))
(declare-fun n192 () Int)
(assert (= n192 (+ n111 n191)))
(declare-fun n193 () Int)
(assert (= n193 (* n112 n85)))
(assert (>= n189 n192))
(assert (>= n190 n193))
(declare-fun n194 () Int)
(assert (= n194 (* n29 n16)))
(declare-fun n195 () Int)
(assert (= n195 (+ n28 n194)))
(declare-fun n196 () Int)
(assert (= n196 (* n29 n17)))
(declare-fun n197 () Int)
(assert (= n197 (* n109 n28)))
(declare-fun n198 () Int)
(assert (= n198 (+ n108 n197)))
(declare-fun n199 () Int)
(assert (= n199 (* n109 n29)))
(assert (>= n195 n198))
(assert (>= n196 n199))
(assert (or (> n90 n10) (> n72 n120) (> n72 n123) (> n72 n93) (> n48 n126) (> n48 n129) (> n48 n132) (> n48 n135) (> n48 n54) (> n45 n138) (> n45 n141) (> n45 n144) (> n45 n147) (> n45 n90) (> n45 n54) (> n150 n153) (> n156 n159)))
(check-sat)
(exit)
