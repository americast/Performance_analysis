print("How many numbers would you like to generate?")
n=parse(Int,readline(STDIN))
print("\nWhat should be the maximum no (minimum 1).?")
k=parse(Int,readline(STDIN))
open("data.txt", "w") do f
  for i in 1:n
    if i!=n
      write(f, "$(rand(1:k)) ")
    else
      write(f, "-1");
    end
  end
end
println("Done!")
