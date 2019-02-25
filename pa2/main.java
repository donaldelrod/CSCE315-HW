import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;

import java.util.*;

public class main {
	public static void main(String[] args) {
			
		boolean testGrammar = false;
		
		if (testGrammar) {
		
			//reads input commands line by line, or from file if 
			//redirection is used
			List<String> lines = new ArrayList<>();
			Scanner scanner = new Scanner(System.in);
			while (scanner.hasNextLine()) {
			   String line = scanner.nextLine();
			   lines.add(line);
			}
			scanner.close();
			
			//this for loop iterates through the list of commands
			//and checks if they are valid
			//if invalid, the number of errors will be > 0
			for (String line : lines) {
				CharStream charStream = CharStreams.fromString(line);
				pa2Lexer lexer = new pa2Lexer(charStream);
				lexer.removeErrorListeners(); // disable lexer warnings
				CommonTokenStream commonTokenStream = new CommonTokenStream(lexer);
				pa2Parser parser = new pa2Parser(commonTokenStream);
				parser.removeErrorListeners(); // disable parser warnings
				
				ParseTree parseTree = parser.program(); // program() auto-created from program parser rule
				String output = parseTree.toStringTree(parser);
				int numErrors = parser.getNumberOfSyntaxErrors();
				System.out.println(output); // the parse tree's flat structure format
				System.out.println(numErrors); // the number of syntax errors generated from the parser
			}
		}
		
		//To test the functionality of each command, toggle these boolean values
		//They are set right now to do the majority of the functions, some just
		//change the table so the others might not be visibly doing things
		
		//when using, make sure that if testCreate is true, testOpen is false and vice versa
		
		//if you toggle testDelete to false and have it save and open, you 
		//can scroll up and see that the table loads as expected.
		//then, if you toggle testDelete to true and have it save and open, you will
		//see the much smaller table after the delete from the previous run in the open statement
		
		boolean testCreate = true,
				testUpdate = false,
				testSelection = true,
				testProjection = true,
				testUnionSameHeader = true,
				testUnionDifferentHeader = true,
				testDifferenceSameHeader = true,
				testDifferenceDifferentHeader = true,
				testRename = false,
				testProduct = true, 
				testComparison = true,
				testDelete = false,
				testSave = true,
				testOpen = false;
		
		Table t = new Table();
		
		if (testCreate) {
			//this is creating a new table
			ArrayList<TypedAttribute> cols = new ArrayList<TypedAttribute>();
			//these are the columns of the table
			cols.add(new TypedAttribute("kind", new VarcharT(20)));
			cols.add(new TypedAttribute("name", new VarcharT(20)));
			cols.add(new TypedAttribute("age", new IntegerT()));
			
			//these are the primary keys of the new table
			ArrayList<String> pks = new ArrayList<String>();
			pks.add("kind");
			pks.add("name");
			
			
			t = dbCommands.createTable("animals", cols, pks);
			dbCommands.showTable(t);
			
			//these are the commands to make a new tuple from TypedAttributes
			TypedAttribute c1 = new TypedAttribute("dog");
			TypedAttribute c2 = new TypedAttribute("sam");
			TypedAttribute c3 = new TypedAttribute(12);
			TypedAttribute[] c4 = new TypedAttribute[]{c1, c2, c3};
			//inserts the tuple into table
			dbCommands.insertTuple_1(t, c4);
			
			//more tuples
			c1 = new TypedAttribute("cat");
			c2 = new TypedAttribute("smokey");
			c3 = new TypedAttribute(18);
			c4 = new TypedAttribute[]{c1, c2, c3};
	
			dbCommands.insertTuple_1(t, c4);
			
			c1 = new TypedAttribute("duck");
			c2 = new TypedAttribute("donald");
			c3 = new TypedAttribute(21);
			c4 = new TypedAttribute[]{c1, c2, c3};
			
			dbCommands.insertTuple_1(t, c4);
			
			c1 = new TypedAttribute("dog");
			c2 = new TypedAttribute("donald");
			c3 = new TypedAttribute(25);
			c4 = new TypedAttribute[]{c1, c2, c3};
			
			dbCommands.insertTuple_1(t, c4);
			
			//this one shouldn't work as a tuple with this pk
			//has already been added
			dbCommands.insertTuple_1(t, c4);
		}
		//--------------------------------Open---------------------------//
		if (testOpen) {
			t = dbCommands.openTable("animals");
		}
				
		dbCommands.showTable(t);
		//--------------------------------Update---------------------------//
		if (testUpdate) {
			
			System.out.println("Update test using VARCHARS...");
			System.out.println("update (kind, name) to (cat, fred) where (kind == dog);\n");
			
			TypedAttribute a1 = new TypedAttribute("kind");
			TypedAttribute a2 = new TypedAttribute("dog");
			
			
			Condition c = new Condition(a1, a2, "==");
			
			//these are the columns to change if the above condition is met
			TypedAttribute b1 = new TypedAttribute("kind");
			TypedAttribute b2 = new TypedAttribute("name");
			ArrayList<TypedAttribute> b3 = new ArrayList<TypedAttribute>();
			b3.add(b1);
			b3.add(b2);
			
			//these are the values the columns that meet the condition
			//will be changed to
			TypedAttribute d1 = new TypedAttribute("cat");
			TypedAttribute d2 = new TypedAttribute("fred");
			ArrayList<TypedAttribute> d3 = new ArrayList<TypedAttribute>();
			d3.add(d1);
			d3.add(d2);
			
			//testing update
			//this should change every tuple that is a dog to a cat named fred
			dbCommands.updateTuple(t, b3, d3, c);
			
			dbCommands.showTable(t);
	

			System.out.println("Update Test using INTEGERS...");
			System.out.println("update (name, age) to (bob, 35) where (age == 12);\n");
			//testing update when numeric conditions are used
			TypedAttribute e1 = new TypedAttribute("age");
			TypedAttribute e2 = new TypedAttribute(12);
			
			
			Condition f = new Condition(e1, e2, "<=");
			
			//these are the columns to change if the above condition is met
			TypedAttribute g1 = new TypedAttribute("name");
			TypedAttribute g2 = new TypedAttribute("age");
			ArrayList<TypedAttribute> g3 = new ArrayList<TypedAttribute>();
			g3.add(g1);
			g3.add(g2);
			
			//these are the values the columns that meet the condition
			//will be changed to
			TypedAttribute h1 = new TypedAttribute("bob");
			TypedAttribute h2 = new TypedAttribute(35);
			ArrayList<TypedAttribute> h3 = new ArrayList<TypedAttribute>();
			h3.add(h1);
			h3.add(h2);
			
			//testing update
			//this should change every tuple that is a dog to a cat named fred
			dbCommands.updateTuple(t, g3, h3, f);
			System.out.println("Updated Table");
			dbCommands.showTable(t);
			
		}
		//--------------------------------Selection------------------------//
		if (testSelection) {
			
			System.out.println("Selection test...");
			System.out.println("select (kind == dog) from table\n");
			
			TypedAttribute a1 = new TypedAttribute("kind");
			TypedAttribute a2 = new TypedAttribute("dog");
			
			Condition c = new Condition(a1, a2, "==");
			
			Table select = dbCommands.selection(t, c);
			System.out.println("Selection Table");
			dbCommands.showTable(select);
			System.out.println("\n\n");
		}
		//--------------------------------Projection----------------------//
		if (testProjection) {
			
			System.out.println("Projection test...");
			System.out.println("project (kind, age)\n");
			
			ArrayList<String> colsToProject = new ArrayList<String>();
			colsToProject.add("kind");
			colsToProject.add("age");
			
			ArrayList<Integer> colIndexes = new ArrayList<Integer>();
			
			Table t2 = dbCommands.projectionS(t, colsToProject);
			System.out.println("Projection Table");
			dbCommands.showTable(t2);
			System.out.println("\n\n");
		}
		//--------------------------------Union - Same headers-------------//
		if (testUnionSameHeader) {
			
			System.out.println("Union Test with compatible tuple sets...");
			System.out.println("(select (kind == dog) from table) + (select (age == 12) from table)\n");
			
			TypedAttribute a1 = new TypedAttribute("kind");
			TypedAttribute a2 = new TypedAttribute("dog");

			Condition c = new Condition(a1, a2, "==");
			
			Table dogs = dbCommands.selection(t, c);
		
			TypedAttribute b1 = new TypedAttribute("age");
			TypedAttribute b2 = new TypedAttribute(18);
			
			Condition d = new Condition(b1, b2, "==");
			
			Table twelve = dbCommands.selection(t, d);

			Table union = dbCommands.union(dogs, twelve);
			System.out.println("Union Table");
			dbCommands.showTable(union);
			System.out.println("\n\n");
		}
		//--------------------------------Union - Different headers-------------//
		if (testUnionDifferentHeader) {
			System.out.println("Union Test with incompatible tuple sets...");
			System.out.println("(project (kind, age) (select (kind == dog) from table)) + (select (age == 12) from table)\n");
			
			TypedAttribute a1 = new TypedAttribute("kind");
			TypedAttribute a2 = new TypedAttribute("dog");
			

			Condition c = new Condition(a1, a2, "==");
			
			Table dogs = dbCommands.selection(t, c);
			//finished selecting all tuples with kind == dog
			//--------------------------------------------------------
			//now projecting the kind and age column
			ArrayList<String> colsToProject = new ArrayList<String>();
			colsToProject.add("kind");
			colsToProject.add("name");
			
			ArrayList<Integer> colIndexes = new ArrayList<Integer>();
			
			//gets the column indexes so the projection 
			//table can have proper header
			for (String colname : colsToProject)
				colIndexes.add(t.getColIndex(colname));
			
			Table project = dbCommands.projectionI(dogs, colIndexes);

			
			//so this is the projection of the result of the selection
			//--------------------------------------------------------
			//now we are making the second selection with no projection
			//this will make not only the number of columns different, but
			//also give different headers
		
			TypedAttribute b1 = new TypedAttribute("age");
			TypedAttribute b2 = new TypedAttribute(12);
			
			
			Condition d = new Condition(b1, b2, ">=");
			
			Table twelve = dbCommands.selection(t, d);
			
			Table union = dbCommands.union(project, twelve);
			
			if (union != null) {
				System.out.println("Union Table");
				dbCommands.showTable(union);
				System.out.println("\n\n");
			}
		}
		//------------------------Differences - Same header-------------//
		if (testDifferenceSameHeader) {
			System.out.println("Difference Test with compatible tuple sets...");
			System.out.println("(select (age >= 12) from table) - (select (kind == dog) from table)\n");
			
			TypedAttribute a1 = new TypedAttribute("kind");
			TypedAttribute a2 = new TypedAttribute("dog");
			
			Condition c = new Condition(a1, a2, "==");
			
			Table dogs = dbCommands.selection(t, c);
			
			TypedAttribute b1 = new TypedAttribute("age");
			TypedAttribute b2 = new TypedAttribute(12);
			
			Condition d = new Condition(b1, b2, ">=");
			
			Table twelve = dbCommands.selection(t, d);
			
			System.out.println("Twelve table");
			dbCommands.showTable(twelve);
			
			System.out.println("Dogs table");
			dbCommands.showTable(dogs);
			
			Table difference = dbCommands.difference(twelve, dogs);
			System.out.println("Difference Table");
			dbCommands.showTable(difference);

			System.out.println("\n\n");
		}
		//------------------------Differences - Different header-------------//
		if (testDifferenceDifferentHeader) {
			System.out.println("Difference Test with incompatible tuple sets...");
			System.out.println("(project (kind, age) (select (kind == dog) from table)) - (select (age == 12) from table)\n");
			
			TypedAttribute a1 = new TypedAttribute("kind");
			TypedAttribute a2 = new TypedAttribute("dog");
			

			Condition c = new Condition(a1, a2, "==");
			
			Table dogs = dbCommands.selection(t, c);
			//finished selecting all tuples with kind == dog
			//--------------------------------------------------------
			//now projecting the kind and age column
			ArrayList<String> colsToProject = new ArrayList<String>();
			colsToProject.add("kind");
			colsToProject.add("name");
			
			ArrayList<Integer> colIndexes = new ArrayList<Integer>();
			
			//gets the column indexes so the projection 
			//table can have proper header
			for (String colname : colsToProject)
				colIndexes.add(t.getColIndex(colname));
			
			Table project = dbCommands.projectionI(dogs, colIndexes);

			//so this is the projection of the result of the selection
			//--------------------------------------------------------
			//now we are making the second selection with no projection
		
			TypedAttribute b1 = new TypedAttribute("age");
			TypedAttribute b2 = new TypedAttribute(12);
			
			
			Condition d = new Condition(b1, b2, ">=");
			
			Table twelve = dbCommands.selection(t, d);
			
			Table difference = dbCommands.difference(project, twelve);
			
			if (difference != null) {
				System.out.println("Difference Table");
				dbCommands.showTable(difference);
				System.out.println("\n\n");
			}
		}
		//----------------------------------------Rename--------------//
		if (testRename) {
			System.out.println("Renaming Test...");
			System.out.println("rename (type, callsign) table\n");
			
			ArrayList<String> newNames = new ArrayList<String>();
			newNames.add("type");
			newNames.add("callsign");
			
			Table renamed = dbCommands.rename(t, newNames);
			
			dbCommands.showTable(t);
			
		}
		//--------------------------------Product---------------------------//
		if (testProduct) {
			System.out.println("Product Test...");
			//System.out.println("(project (kind, age) (select (kind == dog) from table)) - (select (age == 12) from table)\n");
			
			TypedAttribute a1 = new TypedAttribute("kind");
			TypedAttribute a2 = new TypedAttribute("dog");
			

			Condition c = new Condition(a1, a2, "==");
			dbCommands.showTable(t);
			Table dogs = dbCommands.selection(t, c);
			//finished selecting all tuples with kind == dog
			//--------------------------------------------------------
			//now projecting the kind and age column
			ArrayList<String> colsToProject = new ArrayList<String>();
			colsToProject.add("kind");
			colsToProject.add("name");
			
			ArrayList<Integer> colIndexes = new ArrayList<Integer>();
			
			//gets the column indexes so the projection 
			//table can have proper header
			for (String colname : colsToProject)
				colIndexes.add(t.getColIndex(colname));
			
			Table project = dbCommands.projectionI(dogs, colIndexes);

			//so this is the projection of the result of the selection
			//--------------------------------------------------------
			//now we are making the second selection with no projection
		
			TypedAttribute b1 = new TypedAttribute("age");
			TypedAttribute b2 = new TypedAttribute(12);
			
			
			Condition d = new Condition(b1, b2, ">=");
			
			Table twelve = dbCommands.selection(t, d);
			
			Table product = dbCommands.product(dogs, twelve);
			dbCommands.showTable(product);
		}
		//--------------------------------Comparison---------------------------//
		if (testComparison) {
			System.out.println("Comparison Test...");
			System.out.println("select (kind == dog && age > 12) from table\n");
			
			TypedAttribute a1 = new TypedAttribute("kind");
			TypedAttribute a2 = new TypedAttribute("dog");
			
			Condition c = new Condition(a1, a2, "==");
			
			//Table dogs = dbCommands.selection(t, c);
			
			TypedAttribute b1 = new TypedAttribute("age");
			TypedAttribute b2 = new TypedAttribute(12);
			
			Condition d = new Condition(b1, b2, ">");
			
			Comparison comp = new Comparison(c, d, "&&");
			
			Table oldDogs = dbCommands.selection(t, comp);
			
			System.out.println("oldDogs table");
			dbCommands.showTable(oldDogs);
			
			System.out.println("\n\n");
		}
		//--------------------------------Delete---------------------------//
		if (testDelete) {
			System.out.println("Delete Test...");
			System.out.println("delete (kind == dog) from table\n");
			
			TypedAttribute a1 = new TypedAttribute("kind");
			TypedAttribute a2 = new TypedAttribute("dog");
			
			Condition c = new Condition(a1, a2, "==");
			
			Table dogs = dbCommands.deleteTuple(t, c);
			
			System.out.println("table now that dogs have been deleted");
			dbCommands.showTable(dogs);
			
			System.out.println("\n\n");
		}
		//--------------------------------Save---------------------------//
		if (testSave) {
			dbCommands.saveTable(t);
			System.out.println("Table saved to " + t.name + ".db");
		}
	}
	
}
