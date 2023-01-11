; 13. Define a function that returns the depth of a tree 
; Eg. the depth of the tree (a (b (c)) (d) (e (f))) is 3


; myMax(a, b) { 
;              NIL, if a and b not numbers 
;              a, if b not number
;              b, if a not number
;              a, if a > b
;              b, otherwise
;             }
(defun myMax(a b)
  (cond
    ((and (not (numberp a)) (not (numberp b))) nil)
    ((not (numberp b)) a)
    ((not (numberp a)) b)
    ((> a b) a)
    (t b)
  )
)


; findMax(l1l2...ln) { 
;                     NIL, if n = 0
;                     myMax(l1, findMax(l2...ln)), otherwise
;                    }
(defun findMax(l)
  (cond
    ((null l) nil)
    (t (myMax (car l) (findMax (cdr l))))
  )
)


; findDepthTree(tree, k) {
;                         k, if tree is an atom
;                         findMax(findDepthTree(tree_1, k + 1), findDepth(tree_2, k + 1), ... , findDepth(tree_n, k + 1)), otherwise
;                        }
(defun findDepthTree(tree k)
  (cond
    ((atom tree) k)
    (t (apply #'findMax (list (mapcar #' (lambda (a) (findDepthTree a (+ 1 k))) tree))))
  )
)

(defun main(l)
  (findDepthTree l 0)
)


(print (main '(a (b (c)) (d) (e (f)))))