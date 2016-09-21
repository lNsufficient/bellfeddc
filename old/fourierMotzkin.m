function solveable = fourierMotzkin(A,b)
[m,n] = size(A);
if(n == 0)
    solveable = false;
    return;
end
if(n ==1)
    smallestUpperBound = intmax;
    largestLowerBound = intmin;
    for( i = 1:m)
        if(A(i,1) < 0)
            if(b(i)/A(i,1) > largestLowerBound)
                largestLowerBound = b(i)/A(i,1)
            end
        elseif(A(i,1) > 0)
            if(b(i)/A(i,1) < smallestUpperBound)
                smallestUpperBound = b(i)/A(i,1)
            end
        elseif(A(i,1) == 0)
            if(b(i) < 0)
                solveable = false;
                return;
            end
        end
    end
    if(largestLowerBound <= smallestUpperBound)
        solveable = true;
        return;
    end
else
    B = [];
    c = zeros(n-1,1);
    p = 0;
    for i = 1:m
        if(A(i,1) > 0)
            for j = 1:m
                if(A(j,1) < 0)
                   p = p +1;
                   for(k = 2:n)
                       B(p,k-1) = A(i,1)*A(j,k) - A(i,k)*A(j,1);
                   end
                    c(p) = A(i,1) * b(j) - A(j,1)*b(i);
                end
            end
        elseif(A(i,1) == 0)
            p = p+1;
            for k = 2:n
                       B(p,k-1) = A(i,k);
            end
            c(p) = b(i);
        end
    end
    size(B)
    if(size(B) == [0,0])
        solveable = true;
        return;
    end
    B
    c
    solveable = fourierMotzkin(B,c);
    return;
end