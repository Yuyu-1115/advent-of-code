import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class Day1 {
	private static ArrayList<Integer> merge(ArrayList<Integer> left, ArrayList<Integer> right) {
		int leftIndex = 0;
		int rightIndex = 0;
		ArrayList<Integer> res = new ArrayList<>();
		while (true) {
			if (leftIndex < left.size() && rightIndex < right.size()) {
				if (left.get(leftIndex) > right.get(rightIndex)) {
					res.add(right.get(rightIndex));
					rightIndex++;
				}
				else {
					res.add(left.get(leftIndex));
					leftIndex++;
				}
			}
			else if (leftIndex < left.size()) {
					res.add(left.get(leftIndex));
					leftIndex++;
			}
			else if (rightIndex < right.size()) {
					res.add(right.get(rightIndex));
					rightIndex++;
			}
			else {
				break;
			}
		}
		return res;
	}

	private static ArrayList<Integer> mergeSort(ArrayList<Integer> ary) {
		if (ary.size() == 0) {
			return new ArrayList<>();
		}
		if (ary.size() == 1) {
			return ary;
		}
		ArrayList<Integer> leftArray = new ArrayList<>(ary.subList(0, ary.size() / 2));
		ArrayList<Integer> rightArray = new ArrayList<>(ary.subList(ary.size() / 2, ary.size()));

		return merge(mergeSort(leftArray), mergeSort(rightArray));
	}


	public static int part1(ArrayList<Integer> left, ArrayList<Integer> right) {
		int ans = 0;
		for (int i = 0; i < left.size(); i++) {
			ans += Math.abs(left.get(i) - right.get(i));
		}

		return ans;
	}
	public static int part2(ArrayList<Integer> left, ArrayList<Integer> right) {
		int ans = 0;
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int num: right) {
			if (map.getOrDefault(num, -1) == -1) {
				map.put(num, 1);
			}
			else {
				map.put(num, map.get(num) + 1);
			}
		}
		for (int num: left) {
			ans += num * map.getOrDefault(num, 0);
		}

		return ans;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.console().reader());
		ArrayList<Integer> left = new ArrayList<>();
		ArrayList<Integer> right = new ArrayList<>();
		while (sc.hasNextLine()) {
			List<Integer> line = Arrays.stream(sc.nextLine().split("[^0-9]+")).map(str -> Integer.parseInt(str)).toList();
			left.add(line.get(0));
			right.add(line.get(1));
		}
		sc.close();

		ArrayList<Integer> leftSorted = mergeSort(left);
		ArrayList<Integer> rightSorted = mergeSort(right);

		int ansOfPart1 = part1(leftSorted, rightSorted);
		int ansOfPart2 = part2(left, right);

		System.out.println("Part1: " + ansOfPart1);
		System.out.println("Part2: " + ansOfPart2);
	}
}
