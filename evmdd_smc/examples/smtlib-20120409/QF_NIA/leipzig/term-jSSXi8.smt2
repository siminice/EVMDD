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
(assert (= n20 (* n15 n14)))
(declare-fun n21 () Int)
(assert (= n21 (+ n14 n20)))
(declare-fun n22 () Int)
(assert (= n22 (* n15 n15)))
(declare-fun n23 () Int)
(assert (= n23 (* n13 n12)))
(declare-fun n24 () Int)
(assert (= n24 (+ n12 n23)))
(declare-fun n25 () Int)
(assert (= n25 (* n13 n13)))
(declare-fun n26 () Int)
(assert (= n26 (* n22 n21)))
(declare-fun n27 () Int)
(assert (= n27 (+ n21 n26)))
(declare-fun n28 () Int)
(assert (= n28 (* n22 n22)))
(declare-fun n29 () Int)
(assert (= n29 (* n25 n21)))
(declare-fun n30 () Int)
(assert (= n30 (+ n24 n29)))
(declare-fun n31 () Int)
(assert (= n31 (* n25 n22)))
(declare-fun n32 () Int)
(assert (= n32 (* n11 n27)))
(declare-fun n33 () Int)
(assert (= n33 (+ n10 n32)))
(declare-fun n34 () Int)
(assert (= n34 (* n11 n28)))
(declare-fun n35 () Int)
(assert (= n35 (* n34 n21)))
(declare-fun n36 () Int)
(assert (= n36 (+ n33 n35)))
(declare-fun n37 () Int)
(assert (= n37 (* n34 n22)))
(declare-fun n38 () Int)
(assert (= n38 (* n13 n14)))
(declare-fun n39 () Int)
(assert (= n39 (+ n12 n38)))
(declare-fun n40 () Int)
(assert (= n40 (* n13 n15)))
(declare-fun n41 () Int)
(assert (= n41 (* n9 n10)))
(declare-fun n42 () Int)
(assert (= n42 (+ n8 n41)))
(declare-fun n43 () Int)
(assert (= n43 (* n9 n11)))
(declare-fun n44 () Int)
(assert (= n44 (* n25 n24)))
(declare-fun n45 () Int)
(assert (= n45 (+ n24 n44)))
(declare-fun n46 () Int)
(assert (= n46 (* n25 n25)))
(declare-fun n47 () Int)
(assert (= n47 (* n13 n21)))
(declare-fun n48 () Int)
(assert (= n48 (+ n12 n47)))
(declare-fun n49 () Int)
(assert (= n49 (* n13 n22)))
(declare-fun n50 () Int)
(assert (= n50 (* n7 n14)))
(declare-fun n51 () Int)
(assert (= n51 (+ n6 n50)))
(declare-fun n52 () Int)
(assert (= n52 (* n7 n15)))
(declare-fun n53 () Int)
(assert (= n53 (* n9 n14)))
(declare-fun n54 () Int)
(assert (= n54 (+ n8 n53)))
(declare-fun n55 () Int)
(assert (= n55 (* n9 n15)))
(declare-fun n56 () Int)
(assert (= n56 (* n40 n39)))
(declare-fun n57 () Int)
(assert (= n57 (+ n39 n56)))
(declare-fun n58 () Int)
(assert (= n58 (* n40 n40)))
(declare-fun n59 () Int)
(assert (= n59 (* n15 n30)))
(declare-fun n60 () Int)
(assert (= n60 (+ n14 n59)))
(declare-fun n61 () Int)
(assert (= n61 (* n15 n31)))
(declare-fun n62 () Int)
(assert (= n62 (* n28 n14)))
(declare-fun n63 () Int)
(assert (= n63 (+ n27 n62)))
(declare-fun n64 () Int)
(assert (= n64 (* n28 n15)))
(declare-fun n65 () Int)
(assert (= n65 (* n31 n36)))
(declare-fun n66 () Int)
(assert (= n66 (+ n30 n65)))
(declare-fun n67 () Int)
(assert (= n67 (* n31 n37)))
(declare-fun n68 () Int)
(assert (= n68 (* n3 n21)))
(declare-fun n69 () Int)
(assert (= n69 (+ n2 n68)))
(declare-fun n70 () Int)
(assert (= n70 (* n3 n22)))
(declare-fun n71 () Int)
(assert (= n71 (* n3 n48)))
(declare-fun n72 () Int)
(assert (= n72 (+ n2 n71)))
(declare-fun n73 () Int)
(assert (= n73 (* n3 n49)))
(declare-fun n74 () Int)
(assert (= n74 (* n31 n57)))
(declare-fun n75 () Int)
(assert (= n75 (+ n30 n74)))
(declare-fun n76 () Int)
(assert (= n76 (* n31 n58)))
(declare-fun n77 () Int)
(assert (= n77 (* n31 n60)))
(declare-fun n78 () Int)
(assert (= n78 (+ n30 n77)))
(declare-fun n79 () Int)
(assert (= n79 (* n31 n61)))
(declare-fun n80 () Int)
(assert (= n80 (* n7 n10)))
(declare-fun n81 () Int)
(assert (= n81 (+ n6 n80)))
(declare-fun n82 () Int)
(assert (= n82 (* n7 n11)))
(declare-fun n83 () Int)
(assert (= n83 (* n11 n24)))
(declare-fun n84 () Int)
(assert (= n84 (+ n10 n83)))
(declare-fun n85 () Int)
(assert (= n85 (* n11 n25)))
(declare-fun n86 () Int)
(assert (= n86 (* n25 n66)))
(declare-fun n87 () Int)
(assert (= n87 (+ n24 n86)))
(declare-fun n88 () Int)
(assert (= n88 (* n25 n67)))
(declare-fun n89 () Int)
(assert (= n89 (* n28 n27)))
(declare-fun n90 () Int)
(assert (= n90 (+ n27 n89)))
(declare-fun n91 () Int)
(assert (= n91 (* n28 n28)))
(declare-fun n92 () Int)
(assert (= n92 (* n91 n18)))
(declare-fun n93 () Int)
(assert (= n93 (+ n90 n92)))
(declare-fun n94 () Int)
(assert (= n94 (* n91 n19)))
(declare-fun n95 () Int)
(assert (= n95 (* n94 n75)))
(declare-fun n96 () Int)
(assert (= n96 (+ n93 n95)))
(declare-fun n97 () Int)
(assert (= n97 (* n94 n76)))
(declare-fun n98 () Int)
(assert (= n98 (* n49 n36)))
(declare-fun n99 () Int)
(assert (= n99 (+ n48 n98)))
(declare-fun n100 () Int)
(assert (= n100 (* n49 n37)))
(declare-fun n101 () Int)
(assert (= n101 (* n17 n78)))
(declare-fun n102 () Int)
(assert (= n102 (+ n16 n101)))
(declare-fun n103 () Int)
(assert (= n103 (* n17 n79)))
(declare-fun n104 () Int)
(assert (= n104 (* n85 n63)))
(declare-fun n105 () Int)
(assert (= n105 (+ n84 n104)))
(declare-fun n106 () Int)
(assert (= n106 (* n85 n64)))
(declare-fun n107 () Int)
(assert (= n107 (* n3 n45)))
(declare-fun n108 () Int)
(assert (= n108 (+ n2 n107)))
(declare-fun n109 () Int)
(assert (= n109 (* n3 n46)))
(declare-fun n110 () Int)
(assert (= n110 (* n25 n99)))
(declare-fun n111 () Int)
(assert (= n111 (+ n24 n110)))
(declare-fun n112 () Int)
(assert (= n112 (* n25 n100)))
(declare-fun n113 () Int)
(assert (= n113 (* n46 n87)))
(declare-fun n114 () Int)
(assert (= n114 (+ n45 n113)))
(declare-fun n115 () Int)
(assert (= n115 (* n46 n88)))
(declare-fun n116 () Int)
(assert (= n116 (* n15 n39)))
(declare-fun n117 () Int)
(assert (= n117 (+ n14 n116)))
(declare-fun n118 () Int)
(assert (= n118 (* n15 n40)))
(declare-fun n119 () Int)
(assert (= n119 (* n3 n12)))
(declare-fun n120 () Int)
(assert (= n120 (+ n2 n119)))
(declare-fun n121 () Int)
(assert (= n121 (* n3 n13)))
(declare-fun n122 () Int)
(assert (= n122 (* n3 n14)))
(declare-fun n123 () Int)
(assert (= n123 (+ n2 n122)))
(declare-fun n124 () Int)
(assert (= n124 (* n3 n15)))
(declare-fun n125 () Int)
(assert (= n125 (* n22 n30)))
(declare-fun n126 () Int)
(assert (= n126 (+ n21 n125)))
(declare-fun n127 () Int)
(assert (= n127 (* n22 n31)))
(declare-fun n128 () Int)
(assert (= n128 (* n28 n126)))
(declare-fun n129 () Int)
(assert (= n129 (+ n27 n128)))
(declare-fun n130 () Int)
(assert (= n130 (* n28 n127)))
(declare-fun n131 () Int)
(assert (= n131 (* n15 n24)))
(declare-fun n132 () Int)
(assert (= n132 (+ n14 n131)))
(declare-fun n133 () Int)
(assert (= n133 (* n15 n25)))
(declare-fun n134 () Int)
(assert (= n134 (* n121 n96)))
(declare-fun n135 () Int)
(assert (= n135 (+ n120 n134)))
(declare-fun n136 () Int)
(assert (= n136 (* n121 n97)))
(assert (>= n51 n135))
(assert (>= n52 n136))
(declare-fun n137 () Int)
(assert (= n137 (* n3 n96)))
(declare-fun n138 () Int)
(assert (= n138 (+ n2 n137)))
(declare-fun n139 () Int)
(assert (= n139 (* n3 n97)))
(assert (>= n51 n138))
(assert (>= n52 n139))
(declare-fun n140 () Int)
(assert (= n140 (* n9 n75)))
(declare-fun n141 () Int)
(assert (= n141 (+ n8 n140)))
(declare-fun n142 () Int)
(assert (= n142 (* n9 n76)))
(assert (>= n51 n141))
(assert (>= n52 n142))
(declare-fun n143 () Int)
(assert (= n143 (* n73 n57)))
(declare-fun n144 () Int)
(assert (= n144 (+ n72 n143)))
(declare-fun n145 () Int)
(assert (= n145 (* n73 n58)))
(assert (>= n51 n144))
(assert (>= n52 n145))
(declare-fun n146 () Int)
(assert (= n146 (* n70 n57)))
(declare-fun n147 () Int)
(assert (= n147 (+ n69 n146)))
(declare-fun n148 () Int)
(assert (= n148 (* n70 n58)))
(assert (>= n51 n147))
(assert (>= n52 n148))
(declare-fun n149 () Int)
(assert (= n149 (* n3 n117)))
(declare-fun n150 () Int)
(assert (= n150 (+ n2 n149)))
(declare-fun n151 () Int)
(assert (= n151 (* n3 n118)))
(assert (>= n51 n150))
(assert (>= n52 n151))
(assert (>= n51 n123))
(assert (>= n52 n124))
(declare-fun n152 () Int)
(assert (= n152 (* n73 n105)))
(declare-fun n153 () Int)
(assert (= n153 (+ n72 n152)))
(declare-fun n154 () Int)
(assert (= n154 (* n73 n106)))
(assert (>= n81 n153))
(assert (>= n82 n154))
(declare-fun n155 () Int)
(assert (= n155 (* n70 n105)))
(declare-fun n156 () Int)
(assert (= n156 (+ n69 n155)))
(declare-fun n157 () Int)
(assert (= n157 (* n70 n106)))
(assert (>= n81 n156))
(assert (>= n82 n157))
(declare-fun n158 () Int)
(assert (= n158 (* n121 n63)))
(declare-fun n159 () Int)
(assert (= n159 (+ n120 n158)))
(declare-fun n160 () Int)
(assert (= n160 (* n121 n64)))
(assert (>= n81 n159))
(assert (>= n82 n160))
(declare-fun n161 () Int)
(assert (= n161 (* n3 n63)))
(declare-fun n162 () Int)
(assert (= n162 (+ n2 n161)))
(declare-fun n163 () Int)
(assert (= n163 (* n3 n64)))
(assert (>= n81 n162))
(assert (>= n82 n163))
(declare-fun n164 () Int)
(assert (= n164 (* n73 n102)))
(declare-fun n165 () Int)
(assert (= n165 (+ n72 n164)))
(declare-fun n166 () Int)
(assert (= n166 (* n73 n103)))
(assert (>= n54 n165))
(assert (>= n55 n166))
(declare-fun n167 () Int)
(assert (= n167 (* n70 n102)))
(declare-fun n168 () Int)
(assert (= n168 (+ n69 n167)))
(declare-fun n169 () Int)
(assert (= n169 (* n70 n103)))
(assert (>= n54 n168))
(assert (>= n55 n169))
(declare-fun n170 () Int)
(assert (= n170 (* n7 n78)))
(declare-fun n171 () Int)
(assert (= n171 (+ n6 n170)))
(declare-fun n172 () Int)
(assert (= n172 (* n7 n79)))
(assert (>= n54 n171))
(assert (>= n55 n172))
(declare-fun n173 () Int)
(assert (= n173 (* n73 n60)))
(declare-fun n174 () Int)
(assert (= n174 (+ n72 n173)))
(declare-fun n175 () Int)
(assert (= n175 (* n73 n61)))
(assert (>= n54 n174))
(assert (>= n55 n175))
(declare-fun n176 () Int)
(assert (= n176 (* n70 n60)))
(declare-fun n177 () Int)
(assert (= n177 (+ n69 n176)))
(declare-fun n178 () Int)
(assert (= n178 (* n70 n61)))
(assert (>= n54 n177))
(assert (>= n55 n178))
(assert (>= n54 n72))
(assert (>= n55 n73))
(assert (>= n54 n69))
(assert (>= n55 n70))
(declare-fun n179 () Int)
(assert (= n179 (* n124 n114)))
(declare-fun n180 () Int)
(assert (= n180 (+ n123 n179)))
(declare-fun n181 () Int)
(assert (= n181 (* n124 n115)))
(assert (>= n42 n180))
(assert (>= n43 n181))
(declare-fun n182 () Int)
(assert (= n182 (* n109 n111)))
(declare-fun n183 () Int)
(assert (= n183 (+ n108 n182)))
(declare-fun n184 () Int)
(assert (= n184 (* n109 n112)))
(assert (>= n42 n183))
(assert (>= n43 n184))
(declare-fun n185 () Int)
(assert (= n185 (* n109 n66)))
(declare-fun n186 () Int)
(assert (= n186 (+ n108 n185)))
(declare-fun n187 () Int)
(assert (= n187 (* n109 n67)))
(assert (>= n42 n186))
(assert (>= n43 n187))
(declare-fun n188 () Int)
(assert (= n188 (* n109 n99)))
(declare-fun n189 () Int)
(assert (= n189 (+ n108 n188)))
(declare-fun n190 () Int)
(assert (= n190 (* n109 n100)))
(assert (>= n42 n189))
(assert (>= n43 n190))
(declare-fun n191 () Int)
(assert (= n191 (* n3 n87)))
(declare-fun n192 () Int)
(assert (= n192 (+ n2 n191)))
(declare-fun n193 () Int)
(assert (= n193 (* n3 n88)))
(assert (>= n42 n192))
(assert (>= n43 n193))
(declare-fun n194 () Int)
(assert (= n194 (* n3 n111)))
(declare-fun n195 () Int)
(assert (= n195 (+ n2 n194)))
(declare-fun n196 () Int)
(assert (= n196 (* n3 n112)))
(assert (>= n42 n195))
(assert (>= n43 n196))
(declare-fun n197 () Int)
(assert (= n197 (* n3 n66)))
(declare-fun n198 () Int)
(assert (= n198 (+ n2 n197)))
(declare-fun n199 () Int)
(assert (= n199 (* n3 n67)))
(assert (>= n42 n198))
(assert (>= n43 n199))
(declare-fun n200 () Int)
(assert (= n200 (* n73 n36)))
(declare-fun n201 () Int)
(assert (= n201 (+ n72 n200)))
(declare-fun n202 () Int)
(assert (= n202 (* n73 n37)))
(assert (>= n42 n201))
(assert (>= n43 n202))
(declare-fun n203 () Int)
(assert (= n203 (* n70 n36)))
(declare-fun n204 () Int)
(assert (= n204 (+ n69 n203)))
(declare-fun n205 () Int)
(assert (= n205 (* n70 n37)))
(assert (>= n42 n204))
(assert (>= n43 n205))
(declare-fun n206 () Int)
(assert (= n206 (* n3 n39)))
(declare-fun n207 () Int)
(assert (= n207 (+ n2 n206)))
(declare-fun n208 () Int)
(assert (= n208 (* n3 n40)))
(assert (>= n207 n2))
(assert (>= n208 n3))
(declare-fun n209 () Int)
(assert (= n209 (* n3 n10)))
(declare-fun n210 () Int)
(assert (= n210 (+ n2 n209)))
(declare-fun n211 () Int)
(assert (= n211 (* n3 n11)))
(assert (>= n210 n123))
(assert (>= n211 n124))
(declare-fun n212 () Int)
(assert (= n212 (* n17 n14)))
(declare-fun n213 () Int)
(assert (= n213 (+ n16 n212)))
(declare-fun n214 () Int)
(assert (= n214 (* n17 n15)))
(declare-fun n215 () Int)
(assert (= n215 (* n133 n96)))
(declare-fun n216 () Int)
(assert (= n216 (+ n132 n215)))
(declare-fun n217 () Int)
(assert (= n217 (* n133 n97)))
(assert (>= n213 n216))
(assert (>= n214 n217))
(declare-fun n218 () Int)
(assert (= n218 (* n17 n10)))
(declare-fun n219 () Int)
(assert (= n219 (+ n16 n218)))
(declare-fun n220 () Int)
(assert (= n220 (* n17 n11)))
(declare-fun n221 () Int)
(assert (= n221 (* n31 n105)))
(declare-fun n222 () Int)
(assert (= n222 (+ n30 n221)))
(declare-fun n223 () Int)
(assert (= n223 (* n31 n106)))
(assert (>= n219 n222))
(assert (>= n220 n223))
(declare-fun n224 () Int)
(assert (= n224 (* n19 n14)))
(declare-fun n225 () Int)
(assert (= n225 (+ n18 n224)))
(declare-fun n226 () Int)
(assert (= n226 (* n19 n15)))
(declare-fun n227 () Int)
(assert (= n227 (* n130 n102)))
(declare-fun n228 () Int)
(assert (= n228 (+ n129 n227)))
(declare-fun n229 () Int)
(assert (= n229 (* n130 n103)))
(assert (>= n225 n228))
(assert (>= n226 n229))
(declare-fun n230 () Int)
(assert (= n230 (* n19 n10)))
(declare-fun n231 () Int)
(assert (= n231 (+ n18 n230)))
(declare-fun n232 () Int)
(assert (= n232 (* n19 n11)))
(declare-fun n233 () Int)
(assert (= n233 (* n40 n114)))
(declare-fun n234 () Int)
(assert (= n234 (+ n39 n233)))
(declare-fun n235 () Int)
(assert (= n235 (* n40 n115)))
(assert (>= n231 n234))
(assert (>= n232 n235))
(declare-fun n236 () Int)
(assert (= n236 (* n25 n14)))
(declare-fun n237 () Int)
(assert (= n237 (+ n24 n236)))
(declare-fun n238 () Int)
(assert (= n238 (* n25 n15)))
(assert (>= n237 n12))
(assert (>= n238 n13))
(assert true)
(assert (>= n40 1))
(declare-fun n239 () Int)
(assert (= n239 (* n13 n10)))
(declare-fun n240 () Int)
(assert (= n240 (+ n12 n239)))
(declare-fun n241 () Int)
(assert (= n241 (* n13 n11)))
(declare-fun n242 () Int)
(assert (= n242 (* n37 n117)))
(declare-fun n243 () Int)
(assert (= n243 (+ n36 n242)))
(declare-fun n244 () Int)
(assert (= n244 (* n37 n118)))
(assert (>= n240 n243))
(assert (>= n241 n244))
(assert (or (> n51 n135) (> n51 n138) (> n51 n141) (> n51 n144) (> n51 n147) (> n51 n150) (> n51 n123) (> n81 n153) (> n81 n156) (> n81 n159) (> n81 n162) (> n54 n165) (> n54 n168) (> n54 n171) (> n54 n174) (> n54 n177) (> n54 n72) (> n54 n69) (> n42 n180) (> n42 n183) (> n42 n186) (> n42 n189) (> n42 n192) (> n42 n195) (> n42 n198) (> n42 n201) (> n42 n204) (> n207 n2) (> n210 n123)))
(check-sat)
(exit)
