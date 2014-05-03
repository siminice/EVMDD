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
(assert (>= n32 0))
(declare-fun n33 () Int)
(assert (>= n33 0))
(declare-fun n34 () Int)
(assert (>= n34 0))
(declare-fun n35 () Int)
(assert (>= n35 0))
(declare-fun n36 () Int)
(assert (>= n36 0))
(declare-fun n37 () Int)
(assert (>= n37 0))
(declare-fun n38 () Int)
(assert (>= n38 0))
(declare-fun n39 () Int)
(assert (>= n39 0))
(declare-fun n40 () Int)
(assert (>= n40 0))
(declare-fun n41 () Int)
(assert (>= n41 0))
(declare-fun n42 () Int)
(assert (>= n42 0))
(declare-fun n43 () Int)
(assert (>= n43 0))
(declare-fun n44 () Int)
(assert (>= n44 0))
(declare-fun n45 () Int)
(assert (>= n45 0))
(declare-fun n46 () Int)
(assert (>= n46 0))
(declare-fun n47 () Int)
(assert (>= n47 0))
(declare-fun n48 () Int)
(assert (= n48 (* n1 n12)))
(declare-fun n49 () Int)
(assert (= n49 (* n2 n13)))
(declare-fun n50 () Int)
(assert (= n50 (* n3 n14)))
(declare-fun n51 () Int)
(assert (= n51 (+ n49 n50)))
(declare-fun n52 () Int)
(assert (= n52 (+ n48 n51)))
(declare-fun n53 () Int)
(assert (= n53 (+ n0 n52)))
(declare-fun n54 () Int)
(assert (= n54 (* n1 n15)))
(declare-fun n55 () Int)
(assert (= n55 (* n2 n18)))
(declare-fun n56 () Int)
(assert (= n56 (* n3 n21)))
(declare-fun n57 () Int)
(assert (= n57 (+ n55 n56)))
(declare-fun n58 () Int)
(assert (= n58 (* n1 n16)))
(declare-fun n59 () Int)
(assert (= n59 (* n2 n19)))
(declare-fun n60 () Int)
(assert (= n60 (* n3 n22)))
(declare-fun n61 () Int)
(assert (= n61 (+ n59 n60)))
(declare-fun n62 () Int)
(assert (= n62 (* n1 n17)))
(declare-fun n63 () Int)
(assert (= n63 (* n2 n20)))
(declare-fun n64 () Int)
(assert (= n64 (* n3 n23)))
(declare-fun n65 () Int)
(assert (= n65 (+ n63 n64)))
(declare-fun n66 () Int)
(assert (= n66 (+ n54 n57)))
(declare-fun n67 () Int)
(assert (= n67 (+ n58 n61)))
(declare-fun n68 () Int)
(assert (= n68 (+ n62 n65)))
(declare-fun n69 () Int)
(assert (= n69 (* n9 n24)))
(declare-fun n70 () Int)
(assert (= n70 (* n10 n25)))
(declare-fun n71 () Int)
(assert (= n71 (* n11 n26)))
(declare-fun n72 () Int)
(assert (= n72 (+ n70 n71)))
(declare-fun n73 () Int)
(assert (= n73 (+ n69 n72)))
(declare-fun n74 () Int)
(assert (= n74 (+ n8 n73)))
(declare-fun n75 () Int)
(assert (= n75 (* n9 n27)))
(declare-fun n76 () Int)
(assert (= n76 (* n10 n30)))
(declare-fun n77 () Int)
(assert (= n77 (* n11 n33)))
(declare-fun n78 () Int)
(assert (= n78 (+ n76 n77)))
(declare-fun n79 () Int)
(assert (= n79 (* n9 n28)))
(declare-fun n80 () Int)
(assert (= n80 (* n10 n31)))
(declare-fun n81 () Int)
(assert (= n81 (* n11 n34)))
(declare-fun n82 () Int)
(assert (= n82 (+ n80 n81)))
(declare-fun n83 () Int)
(assert (= n83 (* n9 n29)))
(declare-fun n84 () Int)
(assert (= n84 (* n10 n32)))
(declare-fun n85 () Int)
(assert (= n85 (* n11 n35)))
(declare-fun n86 () Int)
(assert (= n86 (+ n84 n85)))
(declare-fun n87 () Int)
(assert (= n87 (+ n75 n78)))
(declare-fun n88 () Int)
(assert (= n88 (+ n79 n82)))
(declare-fun n89 () Int)
(assert (= n89 (+ n83 n86)))
(assert (>= n53 n74))
(assert (>= n66 n87))
(assert (>= n67 n88))
(assert (>= n68 n89))
(declare-fun n90 () Int)
(assert (= n90 (* n5 n24)))
(declare-fun n91 () Int)
(assert (= n91 (* n6 n25)))
(declare-fun n92 () Int)
(assert (= n92 (* n7 n26)))
(declare-fun n93 () Int)
(assert (= n93 (+ n91 n92)))
(declare-fun n94 () Int)
(assert (= n94 (+ n90 n93)))
(declare-fun n95 () Int)
(assert (= n95 (+ n4 n94)))
(declare-fun n96 () Int)
(assert (= n96 (* n5 n27)))
(declare-fun n97 () Int)
(assert (= n97 (* n6 n30)))
(declare-fun n98 () Int)
(assert (= n98 (* n7 n33)))
(declare-fun n99 () Int)
(assert (= n99 (+ n97 n98)))
(declare-fun n100 () Int)
(assert (= n100 (* n5 n28)))
(declare-fun n101 () Int)
(assert (= n101 (* n6 n31)))
(declare-fun n102 () Int)
(assert (= n102 (* n7 n34)))
(declare-fun n103 () Int)
(assert (= n103 (+ n101 n102)))
(declare-fun n104 () Int)
(assert (= n104 (* n5 n29)))
(declare-fun n105 () Int)
(assert (= n105 (* n6 n32)))
(declare-fun n106 () Int)
(assert (= n106 (* n7 n35)))
(declare-fun n107 () Int)
(assert (= n107 (+ n105 n106)))
(declare-fun n108 () Int)
(assert (= n108 (+ n96 n99)))
(declare-fun n109 () Int)
(assert (= n109 (+ n100 n103)))
(declare-fun n110 () Int)
(assert (= n110 (+ n104 n107)))
(declare-fun n111 () Int)
(assert (= n111 (* n1 n36)))
(declare-fun n112 () Int)
(assert (= n112 (* n2 n37)))
(declare-fun n113 () Int)
(assert (= n113 (* n3 n38)))
(declare-fun n114 () Int)
(assert (= n114 (+ n112 n113)))
(declare-fun n115 () Int)
(assert (= n115 (+ n111 n114)))
(declare-fun n116 () Int)
(assert (= n116 (+ n0 n115)))
(declare-fun n117 () Int)
(assert (= n117 (* n1 n39)))
(declare-fun n118 () Int)
(assert (= n118 (* n2 n42)))
(declare-fun n119 () Int)
(assert (= n119 (* n3 n45)))
(declare-fun n120 () Int)
(assert (= n120 (+ n118 n119)))
(declare-fun n121 () Int)
(assert (= n121 (* n1 n40)))
(declare-fun n122 () Int)
(assert (= n122 (* n2 n43)))
(declare-fun n123 () Int)
(assert (= n123 (* n3 n46)))
(declare-fun n124 () Int)
(assert (= n124 (+ n122 n123)))
(declare-fun n125 () Int)
(assert (= n125 (* n1 n41)))
(declare-fun n126 () Int)
(assert (= n126 (* n2 n44)))
(declare-fun n127 () Int)
(assert (= n127 (* n3 n47)))
(declare-fun n128 () Int)
(assert (= n128 (+ n126 n127)))
(declare-fun n129 () Int)
(assert (= n129 (+ n117 n120)))
(declare-fun n130 () Int)
(assert (= n130 (+ n121 n124)))
(declare-fun n131 () Int)
(assert (= n131 (+ n125 n128)))
(assert (>= n95 n116))
(assert (>= n108 n129))
(assert (>= n109 n130))
(assert (>= n110 n131))
(declare-fun n132 () Int)
(assert (= n132 (* n9 n36)))
(declare-fun n133 () Int)
(assert (= n133 (* n10 n37)))
(declare-fun n134 () Int)
(assert (= n134 (* n11 n38)))
(declare-fun n135 () Int)
(assert (= n135 (+ n133 n134)))
(declare-fun n136 () Int)
(assert (= n136 (+ n132 n135)))
(declare-fun n137 () Int)
(assert (= n137 (+ n8 n136)))
(declare-fun n138 () Int)
(assert (= n138 (* n9 n39)))
(declare-fun n139 () Int)
(assert (= n139 (* n10 n42)))
(declare-fun n140 () Int)
(assert (= n140 (* n11 n45)))
(declare-fun n141 () Int)
(assert (= n141 (+ n139 n140)))
(declare-fun n142 () Int)
(assert (= n142 (* n9 n40)))
(declare-fun n143 () Int)
(assert (= n143 (* n10 n43)))
(declare-fun n144 () Int)
(assert (= n144 (* n11 n46)))
(declare-fun n145 () Int)
(assert (= n145 (+ n143 n144)))
(declare-fun n146 () Int)
(assert (= n146 (* n9 n41)))
(declare-fun n147 () Int)
(assert (= n147 (* n10 n44)))
(declare-fun n148 () Int)
(assert (= n148 (* n11 n47)))
(declare-fun n149 () Int)
(assert (= n149 (+ n147 n148)))
(declare-fun n150 () Int)
(assert (= n150 (+ n138 n141)))
(declare-fun n151 () Int)
(assert (= n151 (+ n142 n145)))
(declare-fun n152 () Int)
(assert (= n152 (+ n146 n149)))
(declare-fun n153 () Int)
(assert (= n153 (* n5 n12)))
(declare-fun n154 () Int)
(assert (= n154 (* n6 n13)))
(declare-fun n155 () Int)
(assert (= n155 (* n7 n14)))
(declare-fun n156 () Int)
(assert (= n156 (+ n154 n155)))
(declare-fun n157 () Int)
(assert (= n157 (+ n153 n156)))
(declare-fun n158 () Int)
(assert (= n158 (+ n4 n157)))
(declare-fun n159 () Int)
(assert (= n159 (* n5 n15)))
(declare-fun n160 () Int)
(assert (= n160 (* n6 n18)))
(declare-fun n161 () Int)
(assert (= n161 (* n7 n21)))
(declare-fun n162 () Int)
(assert (= n162 (+ n160 n161)))
(declare-fun n163 () Int)
(assert (= n163 (* n5 n16)))
(declare-fun n164 () Int)
(assert (= n164 (* n6 n19)))
(declare-fun n165 () Int)
(assert (= n165 (* n7 n22)))
(declare-fun n166 () Int)
(assert (= n166 (+ n164 n165)))
(declare-fun n167 () Int)
(assert (= n167 (* n5 n17)))
(declare-fun n168 () Int)
(assert (= n168 (* n6 n20)))
(declare-fun n169 () Int)
(assert (= n169 (* n7 n23)))
(declare-fun n170 () Int)
(assert (= n170 (+ n168 n169)))
(declare-fun n171 () Int)
(assert (= n171 (+ n159 n162)))
(declare-fun n172 () Int)
(assert (= n172 (+ n163 n166)))
(declare-fun n173 () Int)
(assert (= n173 (+ n167 n170)))
(assert (>= n137 n158))
(assert (>= n150 n171))
(assert (>= n151 n172))
(assert (>= n152 n173))
(declare-fun n174 () Int)
(assert (= n174 (* n15 n12)))
(declare-fun n175 () Int)
(assert (= n175 (* n16 n13)))
(declare-fun n176 () Int)
(assert (= n176 (* n17 n14)))
(declare-fun n177 () Int)
(assert (= n177 (+ n175 n176)))
(declare-fun n178 () Int)
(assert (= n178 (* n18 n12)))
(declare-fun n179 () Int)
(assert (= n179 (* n19 n13)))
(declare-fun n180 () Int)
(assert (= n180 (* n20 n14)))
(declare-fun n181 () Int)
(assert (= n181 (+ n179 n180)))
(declare-fun n182 () Int)
(assert (= n182 (* n21 n12)))
(declare-fun n183 () Int)
(assert (= n183 (* n22 n13)))
(declare-fun n184 () Int)
(assert (= n184 (* n23 n14)))
(declare-fun n185 () Int)
(assert (= n185 (+ n183 n184)))
(declare-fun n186 () Int)
(assert (= n186 (+ n174 n177)))
(declare-fun n187 () Int)
(assert (= n187 (+ n178 n181)))
(declare-fun n188 () Int)
(assert (= n188 (+ n182 n185)))
(declare-fun n189 () Int)
(assert (= n189 (+ n12 n186)))
(declare-fun n190 () Int)
(assert (= n190 (+ n13 n187)))
(declare-fun n191 () Int)
(assert (= n191 (+ n14 n188)))
(declare-fun n192 () Int)
(assert (= n192 (* n15 n15)))
(declare-fun n193 () Int)
(assert (= n193 (* n16 n18)))
(declare-fun n194 () Int)
(assert (= n194 (* n17 n21)))
(declare-fun n195 () Int)
(assert (= n195 (+ n193 n194)))
(declare-fun n196 () Int)
(assert (= n196 (* n15 n16)))
(declare-fun n197 () Int)
(assert (= n197 (* n16 n19)))
(declare-fun n198 () Int)
(assert (= n198 (* n17 n22)))
(declare-fun n199 () Int)
(assert (= n199 (+ n197 n198)))
(declare-fun n200 () Int)
(assert (= n200 (* n15 n17)))
(declare-fun n201 () Int)
(assert (= n201 (* n16 n20)))
(declare-fun n202 () Int)
(assert (= n202 (* n17 n23)))
(declare-fun n203 () Int)
(assert (= n203 (+ n201 n202)))
(declare-fun n204 () Int)
(assert (= n204 (* n18 n15)))
(declare-fun n205 () Int)
(assert (= n205 (* n19 n18)))
(declare-fun n206 () Int)
(assert (= n206 (* n20 n21)))
(declare-fun n207 () Int)
(assert (= n207 (+ n205 n206)))
(declare-fun n208 () Int)
(assert (= n208 (* n18 n16)))
(declare-fun n209 () Int)
(assert (= n209 (* n19 n19)))
(declare-fun n210 () Int)
(assert (= n210 (* n20 n22)))
(declare-fun n211 () Int)
(assert (= n211 (+ n209 n210)))
(declare-fun n212 () Int)
(assert (= n212 (* n18 n17)))
(declare-fun n213 () Int)
(assert (= n213 (* n19 n20)))
(declare-fun n214 () Int)
(assert (= n214 (* n20 n23)))
(declare-fun n215 () Int)
(assert (= n215 (+ n213 n214)))
(declare-fun n216 () Int)
(assert (= n216 (* n21 n15)))
(declare-fun n217 () Int)
(assert (= n217 (* n22 n18)))
(declare-fun n218 () Int)
(assert (= n218 (* n23 n21)))
(declare-fun n219 () Int)
(assert (= n219 (+ n217 n218)))
(declare-fun n220 () Int)
(assert (= n220 (* n21 n16)))
(declare-fun n221 () Int)
(assert (= n221 (* n22 n19)))
(declare-fun n222 () Int)
(assert (= n222 (* n23 n22)))
(declare-fun n223 () Int)
(assert (= n223 (+ n221 n222)))
(declare-fun n224 () Int)
(assert (= n224 (* n21 n17)))
(declare-fun n225 () Int)
(assert (= n225 (* n22 n20)))
(declare-fun n226 () Int)
(assert (= n226 (* n23 n23)))
(declare-fun n227 () Int)
(assert (= n227 (+ n225 n226)))
(declare-fun n228 () Int)
(assert (= n228 (+ n192 n195)))
(declare-fun n229 () Int)
(assert (= n229 (+ n196 n199)))
(declare-fun n230 () Int)
(assert (= n230 (+ n200 n203)))
(declare-fun n231 () Int)
(assert (= n231 (+ n204 n207)))
(declare-fun n232 () Int)
(assert (= n232 (+ n208 n211)))
(declare-fun n233 () Int)
(assert (= n233 (+ n212 n215)))
(declare-fun n234 () Int)
(assert (= n234 (+ n216 n219)))
(declare-fun n235 () Int)
(assert (= n235 (+ n220 n223)))
(declare-fun n236 () Int)
(assert (= n236 (+ n224 n227)))
(declare-fun n237 () Int)
(assert (= n237 (* n39 n24)))
(declare-fun n238 () Int)
(assert (= n238 (* n40 n25)))
(declare-fun n239 () Int)
(assert (= n239 (* n41 n26)))
(declare-fun n240 () Int)
(assert (= n240 (+ n238 n239)))
(declare-fun n241 () Int)
(assert (= n241 (* n42 n24)))
(declare-fun n242 () Int)
(assert (= n242 (* n43 n25)))
(declare-fun n243 () Int)
(assert (= n243 (* n44 n26)))
(declare-fun n244 () Int)
(assert (= n244 (+ n242 n243)))
(declare-fun n245 () Int)
(assert (= n245 (* n45 n24)))
(declare-fun n246 () Int)
(assert (= n246 (* n46 n25)))
(declare-fun n247 () Int)
(assert (= n247 (* n47 n26)))
(declare-fun n248 () Int)
(assert (= n248 (+ n246 n247)))
(declare-fun n249 () Int)
(assert (= n249 (+ n237 n240)))
(declare-fun n250 () Int)
(assert (= n250 (+ n241 n244)))
(declare-fun n251 () Int)
(assert (= n251 (+ n245 n248)))
(declare-fun n252 () Int)
(assert (= n252 (+ n36 n249)))
(declare-fun n253 () Int)
(assert (= n253 (+ n37 n250)))
(declare-fun n254 () Int)
(assert (= n254 (+ n38 n251)))
(declare-fun n255 () Int)
(assert (= n255 (* n39 n27)))
(declare-fun n256 () Int)
(assert (= n256 (* n40 n30)))
(declare-fun n257 () Int)
(assert (= n257 (* n41 n33)))
(declare-fun n258 () Int)
(assert (= n258 (+ n256 n257)))
(declare-fun n259 () Int)
(assert (= n259 (* n39 n28)))
(declare-fun n260 () Int)
(assert (= n260 (* n40 n31)))
(declare-fun n261 () Int)
(assert (= n261 (* n41 n34)))
(declare-fun n262 () Int)
(assert (= n262 (+ n260 n261)))
(declare-fun n263 () Int)
(assert (= n263 (* n39 n29)))
(declare-fun n264 () Int)
(assert (= n264 (* n40 n32)))
(declare-fun n265 () Int)
(assert (= n265 (* n41 n35)))
(declare-fun n266 () Int)
(assert (= n266 (+ n264 n265)))
(declare-fun n267 () Int)
(assert (= n267 (* n42 n27)))
(declare-fun n268 () Int)
(assert (= n268 (* n43 n30)))
(declare-fun n269 () Int)
(assert (= n269 (* n44 n33)))
(declare-fun n270 () Int)
(assert (= n270 (+ n268 n269)))
(declare-fun n271 () Int)
(assert (= n271 (* n42 n28)))
(declare-fun n272 () Int)
(assert (= n272 (* n43 n31)))
(declare-fun n273 () Int)
(assert (= n273 (* n44 n34)))
(declare-fun n274 () Int)
(assert (= n274 (+ n272 n273)))
(declare-fun n275 () Int)
(assert (= n275 (* n42 n29)))
(declare-fun n276 () Int)
(assert (= n276 (* n43 n32)))
(declare-fun n277 () Int)
(assert (= n277 (* n44 n35)))
(declare-fun n278 () Int)
(assert (= n278 (+ n276 n277)))
(declare-fun n279 () Int)
(assert (= n279 (* n45 n27)))
(declare-fun n280 () Int)
(assert (= n280 (* n46 n30)))
(declare-fun n281 () Int)
(assert (= n281 (* n47 n33)))
(declare-fun n282 () Int)
(assert (= n282 (+ n280 n281)))
(declare-fun n283 () Int)
(assert (= n283 (* n45 n28)))
(declare-fun n284 () Int)
(assert (= n284 (* n46 n31)))
(declare-fun n285 () Int)
(assert (= n285 (* n47 n34)))
(declare-fun n286 () Int)
(assert (= n286 (+ n284 n285)))
(declare-fun n287 () Int)
(assert (= n287 (* n45 n29)))
(declare-fun n288 () Int)
(assert (= n288 (* n46 n32)))
(declare-fun n289 () Int)
(assert (= n289 (* n47 n35)))
(declare-fun n290 () Int)
(assert (= n290 (+ n288 n289)))
(declare-fun n291 () Int)
(assert (= n291 (+ n255 n258)))
(declare-fun n292 () Int)
(assert (= n292 (+ n259 n262)))
(declare-fun n293 () Int)
(assert (= n293 (+ n263 n266)))
(declare-fun n294 () Int)
(assert (= n294 (+ n267 n270)))
(declare-fun n295 () Int)
(assert (= n295 (+ n271 n274)))
(declare-fun n296 () Int)
(assert (= n296 (+ n275 n278)))
(declare-fun n297 () Int)
(assert (= n297 (+ n279 n282)))
(declare-fun n298 () Int)
(assert (= n298 (+ n283 n286)))
(declare-fun n299 () Int)
(assert (= n299 (+ n287 n290)))
(assert (>= n189 n252))
(assert (>= n190 n253))
(assert (>= n191 n254))
(assert (>= n228 n291))
(assert (>= n229 n292))
(assert (>= n230 n293))
(assert (>= n231 n294))
(assert (>= n232 n295))
(assert (>= n233 n296))
(assert (>= n234 n297))
(assert (>= n235 n298))
(assert (>= n236 n299))
(declare-fun n300 () Int)
(assert (= n300 (* n27 n24)))
(declare-fun n301 () Int)
(assert (= n301 (* n28 n25)))
(declare-fun n302 () Int)
(assert (= n302 (* n29 n26)))
(declare-fun n303 () Int)
(assert (= n303 (+ n301 n302)))
(declare-fun n304 () Int)
(assert (= n304 (* n30 n24)))
(declare-fun n305 () Int)
(assert (= n305 (* n31 n25)))
(declare-fun n306 () Int)
(assert (= n306 (* n32 n26)))
(declare-fun n307 () Int)
(assert (= n307 (+ n305 n306)))
(declare-fun n308 () Int)
(assert (= n308 (* n33 n24)))
(declare-fun n309 () Int)
(assert (= n309 (* n34 n25)))
(declare-fun n310 () Int)
(assert (= n310 (* n35 n26)))
(declare-fun n311 () Int)
(assert (= n311 (+ n309 n310)))
(declare-fun n312 () Int)
(assert (= n312 (+ n300 n303)))
(declare-fun n313 () Int)
(assert (= n313 (+ n304 n307)))
(declare-fun n314 () Int)
(assert (= n314 (+ n308 n311)))
(declare-fun n315 () Int)
(assert (= n315 (+ n24 n312)))
(declare-fun n316 () Int)
(assert (= n316 (+ n25 n313)))
(declare-fun n317 () Int)
(assert (= n317 (+ n26 n314)))
(declare-fun n318 () Int)
(assert (= n318 (* n27 n27)))
(declare-fun n319 () Int)
(assert (= n319 (* n28 n30)))
(declare-fun n320 () Int)
(assert (= n320 (* n29 n33)))
(declare-fun n321 () Int)
(assert (= n321 (+ n319 n320)))
(declare-fun n322 () Int)
(assert (= n322 (* n27 n28)))
(declare-fun n323 () Int)
(assert (= n323 (* n28 n31)))
(declare-fun n324 () Int)
(assert (= n324 (* n29 n34)))
(declare-fun n325 () Int)
(assert (= n325 (+ n323 n324)))
(declare-fun n326 () Int)
(assert (= n326 (* n27 n29)))
(declare-fun n327 () Int)
(assert (= n327 (* n28 n32)))
(declare-fun n328 () Int)
(assert (= n328 (* n29 n35)))
(declare-fun n329 () Int)
(assert (= n329 (+ n327 n328)))
(declare-fun n330 () Int)
(assert (= n330 (* n30 n27)))
(declare-fun n331 () Int)
(assert (= n331 (* n31 n30)))
(declare-fun n332 () Int)
(assert (= n332 (* n32 n33)))
(declare-fun n333 () Int)
(assert (= n333 (+ n331 n332)))
(declare-fun n334 () Int)
(assert (= n334 (* n30 n28)))
(declare-fun n335 () Int)
(assert (= n335 (* n31 n31)))
(declare-fun n336 () Int)
(assert (= n336 (* n32 n34)))
(declare-fun n337 () Int)
(assert (= n337 (+ n335 n336)))
(declare-fun n338 () Int)
(assert (= n338 (* n30 n29)))
(declare-fun n339 () Int)
(assert (= n339 (* n31 n32)))
(declare-fun n340 () Int)
(assert (= n340 (* n32 n35)))
(declare-fun n341 () Int)
(assert (= n341 (+ n339 n340)))
(declare-fun n342 () Int)
(assert (= n342 (* n33 n27)))
(declare-fun n343 () Int)
(assert (= n343 (* n34 n30)))
(declare-fun n344 () Int)
(assert (= n344 (* n35 n33)))
(declare-fun n345 () Int)
(assert (= n345 (+ n343 n344)))
(declare-fun n346 () Int)
(assert (= n346 (* n33 n28)))
(declare-fun n347 () Int)
(assert (= n347 (* n34 n31)))
(declare-fun n348 () Int)
(assert (= n348 (* n35 n34)))
(declare-fun n349 () Int)
(assert (= n349 (+ n347 n348)))
(declare-fun n350 () Int)
(assert (= n350 (* n33 n29)))
(declare-fun n351 () Int)
(assert (= n351 (* n34 n32)))
(declare-fun n352 () Int)
(assert (= n352 (* n35 n35)))
(declare-fun n353 () Int)
(assert (= n353 (+ n351 n352)))
(declare-fun n354 () Int)
(assert (= n354 (+ n318 n321)))
(declare-fun n355 () Int)
(assert (= n355 (+ n322 n325)))
(declare-fun n356 () Int)
(assert (= n356 (+ n326 n329)))
(declare-fun n357 () Int)
(assert (= n357 (+ n330 n333)))
(declare-fun n358 () Int)
(assert (= n358 (+ n334 n337)))
(declare-fun n359 () Int)
(assert (= n359 (+ n338 n341)))
(declare-fun n360 () Int)
(assert (= n360 (+ n342 n345)))
(declare-fun n361 () Int)
(assert (= n361 (+ n346 n349)))
(declare-fun n362 () Int)
(assert (= n362 (+ n350 n353)))
(declare-fun n363 () Int)
(assert (= n363 (* n15 n36)))
(declare-fun n364 () Int)
(assert (= n364 (* n16 n37)))
(declare-fun n365 () Int)
(assert (= n365 (* n17 n38)))
(declare-fun n366 () Int)
(assert (= n366 (+ n364 n365)))
(declare-fun n367 () Int)
(assert (= n367 (* n18 n36)))
(declare-fun n368 () Int)
(assert (= n368 (* n19 n37)))
(declare-fun n369 () Int)
(assert (= n369 (* n20 n38)))
(declare-fun n370 () Int)
(assert (= n370 (+ n368 n369)))
(declare-fun n371 () Int)
(assert (= n371 (* n21 n36)))
(declare-fun n372 () Int)
(assert (= n372 (* n22 n37)))
(declare-fun n373 () Int)
(assert (= n373 (* n23 n38)))
(declare-fun n374 () Int)
(assert (= n374 (+ n372 n373)))
(declare-fun n375 () Int)
(assert (= n375 (+ n363 n366)))
(declare-fun n376 () Int)
(assert (= n376 (+ n367 n370)))
(declare-fun n377 () Int)
(assert (= n377 (+ n371 n374)))
(declare-fun n378 () Int)
(assert (= n378 (+ n12 n375)))
(declare-fun n379 () Int)
(assert (= n379 (+ n13 n376)))
(declare-fun n380 () Int)
(assert (= n380 (+ n14 n377)))
(declare-fun n381 () Int)
(assert (= n381 (* n15 n39)))
(declare-fun n382 () Int)
(assert (= n382 (* n16 n42)))
(declare-fun n383 () Int)
(assert (= n383 (* n17 n45)))
(declare-fun n384 () Int)
(assert (= n384 (+ n382 n383)))
(declare-fun n385 () Int)
(assert (= n385 (* n15 n40)))
(declare-fun n386 () Int)
(assert (= n386 (* n16 n43)))
(declare-fun n387 () Int)
(assert (= n387 (* n17 n46)))
(declare-fun n388 () Int)
(assert (= n388 (+ n386 n387)))
(declare-fun n389 () Int)
(assert (= n389 (* n15 n41)))
(declare-fun n390 () Int)
(assert (= n390 (* n16 n44)))
(declare-fun n391 () Int)
(assert (= n391 (* n17 n47)))
(declare-fun n392 () Int)
(assert (= n392 (+ n390 n391)))
(declare-fun n393 () Int)
(assert (= n393 (* n18 n39)))
(declare-fun n394 () Int)
(assert (= n394 (* n19 n42)))
(declare-fun n395 () Int)
(assert (= n395 (* n20 n45)))
(declare-fun n396 () Int)
(assert (= n396 (+ n394 n395)))
(declare-fun n397 () Int)
(assert (= n397 (* n18 n40)))
(declare-fun n398 () Int)
(assert (= n398 (* n19 n43)))
(declare-fun n399 () Int)
(assert (= n399 (* n20 n46)))
(declare-fun n400 () Int)
(assert (= n400 (+ n398 n399)))
(declare-fun n401 () Int)
(assert (= n401 (* n18 n41)))
(declare-fun n402 () Int)
(assert (= n402 (* n19 n44)))
(declare-fun n403 () Int)
(assert (= n403 (* n20 n47)))
(declare-fun n404 () Int)
(assert (= n404 (+ n402 n403)))
(declare-fun n405 () Int)
(assert (= n405 (* n21 n39)))
(declare-fun n406 () Int)
(assert (= n406 (* n22 n42)))
(declare-fun n407 () Int)
(assert (= n407 (* n23 n45)))
(declare-fun n408 () Int)
(assert (= n408 (+ n406 n407)))
(declare-fun n409 () Int)
(assert (= n409 (* n21 n40)))
(declare-fun n410 () Int)
(assert (= n410 (* n22 n43)))
(declare-fun n411 () Int)
(assert (= n411 (* n23 n46)))
(declare-fun n412 () Int)
(assert (= n412 (+ n410 n411)))
(declare-fun n413 () Int)
(assert (= n413 (* n21 n41)))
(declare-fun n414 () Int)
(assert (= n414 (* n22 n44)))
(declare-fun n415 () Int)
(assert (= n415 (* n23 n47)))
(declare-fun n416 () Int)
(assert (= n416 (+ n414 n415)))
(declare-fun n417 () Int)
(assert (= n417 (+ n381 n384)))
(declare-fun n418 () Int)
(assert (= n418 (+ n385 n388)))
(declare-fun n419 () Int)
(assert (= n419 (+ n389 n392)))
(declare-fun n420 () Int)
(assert (= n420 (+ n393 n396)))
(declare-fun n421 () Int)
(assert (= n421 (+ n397 n400)))
(declare-fun n422 () Int)
(assert (= n422 (+ n401 n404)))
(declare-fun n423 () Int)
(assert (= n423 (+ n405 n408)))
(declare-fun n424 () Int)
(assert (= n424 (+ n409 n412)))
(declare-fun n425 () Int)
(assert (= n425 (+ n413 n416)))
(assert (>= n315 n378))
(assert (>= n316 n379))
(assert (>= n317 n380))
(assert (>= n354 n417))
(assert (>= n355 n418))
(assert (>= n356 n419))
(assert (>= n357 n420))
(assert (>= n358 n421))
(assert (>= n359 n422))
(assert (>= n360 n423))
(assert (>= n361 n424))
(assert (>= n362 n425))
(declare-fun n426 () Int)
(assert (= n426 (* n39 n36)))
(declare-fun n427 () Int)
(assert (= n427 (* n40 n37)))
(declare-fun n428 () Int)
(assert (= n428 (* n41 n38)))
(declare-fun n429 () Int)
(assert (= n429 (+ n427 n428)))
(declare-fun n430 () Int)
(assert (= n430 (* n42 n36)))
(declare-fun n431 () Int)
(assert (= n431 (* n43 n37)))
(declare-fun n432 () Int)
(assert (= n432 (* n44 n38)))
(declare-fun n433 () Int)
(assert (= n433 (+ n431 n432)))
(declare-fun n434 () Int)
(assert (= n434 (* n45 n36)))
(declare-fun n435 () Int)
(assert (= n435 (* n46 n37)))
(declare-fun n436 () Int)
(assert (= n436 (* n47 n38)))
(declare-fun n437 () Int)
(assert (= n437 (+ n435 n436)))
(declare-fun n438 () Int)
(assert (= n438 (+ n426 n429)))
(declare-fun n439 () Int)
(assert (= n439 (+ n430 n433)))
(declare-fun n440 () Int)
(assert (= n440 (+ n434 n437)))
(declare-fun n441 () Int)
(assert (= n441 (+ n36 n438)))
(declare-fun n442 () Int)
(assert (= n442 (+ n37 n439)))
(declare-fun n443 () Int)
(assert (= n443 (+ n38 n440)))
(declare-fun n444 () Int)
(assert (= n444 (* n39 n39)))
(declare-fun n445 () Int)
(assert (= n445 (* n40 n42)))
(declare-fun n446 () Int)
(assert (= n446 (* n41 n45)))
(declare-fun n447 () Int)
(assert (= n447 (+ n445 n446)))
(declare-fun n448 () Int)
(assert (= n448 (* n39 n40)))
(declare-fun n449 () Int)
(assert (= n449 (* n40 n43)))
(declare-fun n450 () Int)
(assert (= n450 (* n41 n46)))
(declare-fun n451 () Int)
(assert (= n451 (+ n449 n450)))
(declare-fun n452 () Int)
(assert (= n452 (* n39 n41)))
(declare-fun n453 () Int)
(assert (= n453 (* n40 n44)))
(declare-fun n454 () Int)
(assert (= n454 (* n41 n47)))
(declare-fun n455 () Int)
(assert (= n455 (+ n453 n454)))
(declare-fun n456 () Int)
(assert (= n456 (* n42 n39)))
(declare-fun n457 () Int)
(assert (= n457 (* n43 n42)))
(declare-fun n458 () Int)
(assert (= n458 (* n44 n45)))
(declare-fun n459 () Int)
(assert (= n459 (+ n457 n458)))
(declare-fun n460 () Int)
(assert (= n460 (* n42 n40)))
(declare-fun n461 () Int)
(assert (= n461 (* n43 n43)))
(declare-fun n462 () Int)
(assert (= n462 (* n44 n46)))
(declare-fun n463 () Int)
(assert (= n463 (+ n461 n462)))
(declare-fun n464 () Int)
(assert (= n464 (* n42 n41)))
(declare-fun n465 () Int)
(assert (= n465 (* n43 n44)))
(declare-fun n466 () Int)
(assert (= n466 (* n44 n47)))
(declare-fun n467 () Int)
(assert (= n467 (+ n465 n466)))
(declare-fun n468 () Int)
(assert (= n468 (* n45 n39)))
(declare-fun n469 () Int)
(assert (= n469 (* n46 n42)))
(declare-fun n470 () Int)
(assert (= n470 (* n47 n45)))
(declare-fun n471 () Int)
(assert (= n471 (+ n469 n470)))
(declare-fun n472 () Int)
(assert (= n472 (* n45 n40)))
(declare-fun n473 () Int)
(assert (= n473 (* n46 n43)))
(declare-fun n474 () Int)
(assert (= n474 (* n47 n46)))
(declare-fun n475 () Int)
(assert (= n475 (+ n473 n474)))
(declare-fun n476 () Int)
(assert (= n476 (* n45 n41)))
(declare-fun n477 () Int)
(assert (= n477 (* n46 n44)))
(declare-fun n478 () Int)
(assert (= n478 (* n47 n47)))
(declare-fun n479 () Int)
(assert (= n479 (+ n477 n478)))
(declare-fun n480 () Int)
(assert (= n480 (+ n444 n447)))
(declare-fun n481 () Int)
(assert (= n481 (+ n448 n451)))
(declare-fun n482 () Int)
(assert (= n482 (+ n452 n455)))
(declare-fun n483 () Int)
(assert (= n483 (+ n456 n459)))
(declare-fun n484 () Int)
(assert (= n484 (+ n460 n463)))
(declare-fun n485 () Int)
(assert (= n485 (+ n464 n467)))
(declare-fun n486 () Int)
(assert (= n486 (+ n468 n471)))
(declare-fun n487 () Int)
(assert (= n487 (+ n472 n475)))
(declare-fun n488 () Int)
(assert (= n488 (+ n476 n479)))
(declare-fun n489 () Int)
(assert (= n489 (* n27 n12)))
(declare-fun n490 () Int)
(assert (= n490 (* n28 n13)))
(declare-fun n491 () Int)
(assert (= n491 (* n29 n14)))
(declare-fun n492 () Int)
(assert (= n492 (+ n490 n491)))
(declare-fun n493 () Int)
(assert (= n493 (* n30 n12)))
(declare-fun n494 () Int)
(assert (= n494 (* n31 n13)))
(declare-fun n495 () Int)
(assert (= n495 (* n32 n14)))
(declare-fun n496 () Int)
(assert (= n496 (+ n494 n495)))
(declare-fun n497 () Int)
(assert (= n497 (* n33 n12)))
(declare-fun n498 () Int)
(assert (= n498 (* n34 n13)))
(declare-fun n499 () Int)
(assert (= n499 (* n35 n14)))
(declare-fun n500 () Int)
(assert (= n500 (+ n498 n499)))
(declare-fun n501 () Int)
(assert (= n501 (+ n489 n492)))
(declare-fun n502 () Int)
(assert (= n502 (+ n493 n496)))
(declare-fun n503 () Int)
(assert (= n503 (+ n497 n500)))
(declare-fun n504 () Int)
(assert (= n504 (+ n24 n501)))
(declare-fun n505 () Int)
(assert (= n505 (+ n25 n502)))
(declare-fun n506 () Int)
(assert (= n506 (+ n26 n503)))
(declare-fun n507 () Int)
(assert (= n507 (* n27 n15)))
(declare-fun n508 () Int)
(assert (= n508 (* n28 n18)))
(declare-fun n509 () Int)
(assert (= n509 (* n29 n21)))
(declare-fun n510 () Int)
(assert (= n510 (+ n508 n509)))
(declare-fun n511 () Int)
(assert (= n511 (* n27 n16)))
(declare-fun n512 () Int)
(assert (= n512 (* n28 n19)))
(declare-fun n513 () Int)
(assert (= n513 (* n29 n22)))
(declare-fun n514 () Int)
(assert (= n514 (+ n512 n513)))
(declare-fun n515 () Int)
(assert (= n515 (* n27 n17)))
(declare-fun n516 () Int)
(assert (= n516 (* n28 n20)))
(declare-fun n517 () Int)
(assert (= n517 (* n29 n23)))
(declare-fun n518 () Int)
(assert (= n518 (+ n516 n517)))
(declare-fun n519 () Int)
(assert (= n519 (* n30 n15)))
(declare-fun n520 () Int)
(assert (= n520 (* n31 n18)))
(declare-fun n521 () Int)
(assert (= n521 (* n32 n21)))
(declare-fun n522 () Int)
(assert (= n522 (+ n520 n521)))
(declare-fun n523 () Int)
(assert (= n523 (* n30 n16)))
(declare-fun n524 () Int)
(assert (= n524 (* n31 n19)))
(declare-fun n525 () Int)
(assert (= n525 (* n32 n22)))
(declare-fun n526 () Int)
(assert (= n526 (+ n524 n525)))
(declare-fun n527 () Int)
(assert (= n527 (* n30 n17)))
(declare-fun n528 () Int)
(assert (= n528 (* n31 n20)))
(declare-fun n529 () Int)
(assert (= n529 (* n32 n23)))
(declare-fun n530 () Int)
(assert (= n530 (+ n528 n529)))
(declare-fun n531 () Int)
(assert (= n531 (* n33 n15)))
(declare-fun n532 () Int)
(assert (= n532 (* n34 n18)))
(declare-fun n533 () Int)
(assert (= n533 (* n35 n21)))
(declare-fun n534 () Int)
(assert (= n534 (+ n532 n533)))
(declare-fun n535 () Int)
(assert (= n535 (* n33 n16)))
(declare-fun n536 () Int)
(assert (= n536 (* n34 n19)))
(declare-fun n537 () Int)
(assert (= n537 (* n35 n22)))
(declare-fun n538 () Int)
(assert (= n538 (+ n536 n537)))
(declare-fun n539 () Int)
(assert (= n539 (* n33 n17)))
(declare-fun n540 () Int)
(assert (= n540 (* n34 n20)))
(declare-fun n541 () Int)
(assert (= n541 (* n35 n23)))
(declare-fun n542 () Int)
(assert (= n542 (+ n540 n541)))
(declare-fun n543 () Int)
(assert (= n543 (+ n507 n510)))
(declare-fun n544 () Int)
(assert (= n544 (+ n511 n514)))
(declare-fun n545 () Int)
(assert (= n545 (+ n515 n518)))
(declare-fun n546 () Int)
(assert (= n546 (+ n519 n522)))
(declare-fun n547 () Int)
(assert (= n547 (+ n523 n526)))
(declare-fun n548 () Int)
(assert (= n548 (+ n527 n530)))
(declare-fun n549 () Int)
(assert (= n549 (+ n531 n534)))
(declare-fun n550 () Int)
(assert (= n550 (+ n535 n538)))
(declare-fun n551 () Int)
(assert (= n551 (+ n539 n542)))
(assert (>= n441 n504))
(assert (>= n442 n505))
(assert (>= n443 n506))
(assert (>= n480 n543))
(assert (>= n481 n544))
(assert (>= n482 n545))
(assert (>= n483 n546))
(assert (>= n484 n547))
(assert (>= n485 n548))
(assert (>= n486 n549))
(assert (>= n487 n550))
(assert (>= n488 n551))
(assert (or (> n53 n74) (> n95 n116) (> n137 n158)))
(check-sat)
(exit)
