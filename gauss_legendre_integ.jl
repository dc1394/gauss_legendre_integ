using FastGaussQuadrature
using Printf

const n = 10000

function setup()
    return gausslegendre(n)
end

function func(x)
    return 0.5 * (1.0 / sqrt(x))   
end

function integ(f, x1, x2, n, x, w)
    xm = 0.5 * (x1 + x2);
    xr = 0.5 * (x2 - x1);

    sum = 0.0;
    for i in 1:n
		sum += w[i] * f(xm + xr * x[i]);
    end

    return sum * xr;
end

function main()
    x, w = setup()
    @printf "積分結果 = %.14f\n" integ(func, 1.0, 4.0, n, x, w)
end
@time main()