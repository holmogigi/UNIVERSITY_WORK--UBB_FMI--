1. Let X have one of the following distributions: X ∈ N(µ, σ) (normal), X ∈ T(n)
(Student), X ∈ χ2(n), or X ∈ F(m, n) (Fischer). Compute the following:

a) P(X ≤ 0) and P(X ≥ 0);

b) P(−1 ≤ X ≤ 1) and P(X ≤ −1 or X ≥ 1);

c) the value xα such that P(X < xα) = α, for α ∈ (0, 1) (xα is called the quantile of order α);

d) the value xβ such that P(X > xβ) = β, for β ∈ (0, 1) (xβ is the quantile of
order 1 − β).

2. Approximations of the Binomial distribution
• Normal approximation of the binomial distribution: For moderate values of p (0.05 ≤ p ≤ 0.95) and large values of n (n → ∞), Bino(n, p) ≈ Norm ( µ = np, σ = q np(1 − p) ).
Write a Matlab code to visualize how the binomial distribution gradually takes
the shape of the normal distribution as n → ∞.
• Poisson approximation of the binomial distribution: If n ≥ 30 and p ≤ 0.05,
then
Bino(n, p) ≈ Poisson(λ = np)
