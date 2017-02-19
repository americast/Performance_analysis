n=parse(Int,readline(STDIN))
println("No. of numbers: 10e$(div(n,10))")
#print("\nWhat should be the maximum no (minimum 1).? ")
k=100000
open("data.txt", "w") do f
  write(f, "$(n) ");
  for i in 1:n+1
    if i!=n+1
      write(f, "$(rand(1:k)) ")
    else
      write(f, "-1");
    end
  end
end
