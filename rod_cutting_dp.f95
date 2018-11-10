program RodCutting
    implicit none

    integer :: rod_length, profit
    integer, allocatable, dimension(:) :: prices

    prices = (/ 1, 5, 8, 9, 10, 17, 17, 20 /)
    rod_length = 8

    profit = calculate_profit(rod_length, prices)

    print *, "The best profit for a rod of length ", rod_length, " is ", profit, "."

contains
    function calculate_profit(rod_length, prices) result(profit)
        implicit none

        integer, intent(in) :: rod_length
        integer, dimension(rod_length), intent(in) :: prices
        integer, dimension(rod_length+1) :: table
        integer :: profit, ii, jj

        table(1) = 0
        do ii = 2, rod_length+1
            profit = 0
            do jj = 1, ii-1
                profit = max_value(profit, prices(jj) + table(ii-jj))
            end do
            table(ii) = profit
        end do

    end function calculate_profit

    function max_value(v1, v2) result(max)
        implicit none

        integer, intent(in) :: v1, v2
        integer :: max

        if (v1 >= v2) then
            max = v1
        else
            max = v2
        end if

    end function max_value

end program