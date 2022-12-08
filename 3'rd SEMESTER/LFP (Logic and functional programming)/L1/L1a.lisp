;a) Write a function to return the dot product of two vectors.
; TODO CHECK LENGHT
; dotProduct(l1l2...ln, k1k2...km) { 
;                                   0 , if n = 0
;                                   l1*l2 + dotProduct(l2...ln, k2...km) , otherwise
;                                  {
(defun dotProduct(l k)
  (cond
    ((null l) 0)
    (t (+ (* (car l) (car k)) (dotProduct (cdr l) (cdr k))))
  )
)


;b) Write a function to return the depth of a list. 

; myMax(a, b) { 
;               a , if a > b
;               b ,  otherwise
;             }
(defun myMax (a b)
  (cond
    ((> a b) a)
    (t b)
  )
)

; findDepth(l1l2...ln, c) { 
;                           c , if n = 0
;                           myMax(findDepth(l1,c+1), findDepth(l2...ln, c)) , if l1 is a list
;                           findDepth(l2...ln, c) , otherwise
;                         }
(defun findDepth (l c)
  (cond
    ((null l) c)
    ((listp (car l)) (myMax (findDepth (car l) (+ c 1)) (findDepth (cdr l) c)))
    (t (findDepth (cdr l) c))
  )
)

; main(l1l2...ln) { 
;                   findDepth(l1l2...ln, 1)
;                 }
(defun main(l)
  (cond
    (t (findDepth l 1))
  )
)


; c) Write a function to sort a linear list without keeping the double values.

; insert(l1l2...ln, elem) {
;                           list(elem) , if n = 0
;                           l1l2...ln , if l1 = elem
;                           {elem} U l1l2...ln, if elem < l1
;                           {l1} U insert(l2...ln, elem) , otherwise
;                         }
(defun insert (l e)
  (cond
    ((null l) (list e))
    ((= (car l) e) l)
    ((< e (car l)) (cons e l))
    (t (cons (car l) (insert (cdr l) e)))
  )
)

; sortare(l1l2...ln) { 
;                      NIL , if n = 0
;                      insert(sortare(l2...ln), l1) , otherwise
;                    }
(defun sortare (l)
  (cond
    ((null l) nil)
    (t (insert (sortare (cdr l)) (car l)))
  )
)


; d) Write a function to return the intersection of two sets.

; contains(elem, l1l2...ln) { 
;                             NIL, if n = 0
;                             true, if l1 = elem
;                             contains(elem, l2...ln), otherwise
;                           }
(defun contains(e l)
  (cond
    ((null l) nil)
    ((equal (car l) e) t)
    (t (contains e (cdr l)))
  )
)

; intersection(l1l2...ln, p1p2...pm) { 
;                                      NIL , if n = 0
;                                      {l1} U intersection(l2...ln, p1p2...pm) , if contains(l1, p1p2...pm)=true
;                                      intersection(l2...ln, p1p2...pm) , otherwise
;                                    }
(defun intersection_(l p)
  (cond
    ((null l) NIL)
    ((contains (car l) p) (cons (car l) (intersection_ (cdr l) p)))
    (t (intersection_ (cdr l) p))
  )
)




(print (dotProduct '(1 2 3) '(4 5 6)))
(print (main '(1 2 3 4 5 6 7)))
(print (sortare '(84 727 82 94 1 1 1 1 84)))
(print (intersection_ '(8 3 5 67) '(5 2 56 9 1 3)))