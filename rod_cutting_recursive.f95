program RodCutting
    implicit none

    integer :: rod_length, profit
    integer, allocatable, dimension(:) :: prices

    ! prices = (/ 1, 5, 8, 9, 10, 17, 17, 20 /)
    prices = (/ 3, 5, 8, 9, 10, 17, 17, 20 /)
    rod_length = 8

    profit = calculate_profit(rod_length, prices)

    print *, "The best profit for a rod of length ", rod_length, " is ", profit, "."

contains
    recursive function calculate_profit(rod_length, prices) result(profit)
        implicit none

        integer, intent(in) :: rod_length
        integer, dimension(rod_length), intent(in) :: prices
        integer :: profit, ii

        ! Base case
        if (rod_length <= 0) then
            profit = 0
        else
            ! Recursive loop
            profit = 0
            do ii = 1, rod_length
                profit = max_value(profit, prices(ii) + calculate_profit(rod_length-ii, prices(1:rod_length-ii)))
            end do
        end if

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