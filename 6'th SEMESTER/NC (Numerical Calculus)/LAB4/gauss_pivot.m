function x = gauss_pivot(A,b)
         [r,n]= size(A);
         x= zeros(size(b));
         A= [A,b];
         for j= 1:n-1
             [v,p]= max(abs(A(j:r,j)));
             p=p+j-1;
             if p~=j
                 A([p,j],:)= A([j,p],:)
             end
             for i=j+1:r
                 m= A(i,j)/A(j,j);
                 A(i,1:n)= A(i,1:n)-m*A(j,1:n);
             end
         end
         x=backward_subs(A(:,1:n), A(:,n+1));
end
