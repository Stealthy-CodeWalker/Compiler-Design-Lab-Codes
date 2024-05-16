import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class LexicalAnalyzer {
    private static final String INPUT = "int x = 42; double y = 3.14;x=32*8";
    private static final Pattern REGEX_PATTERN = Pattern.compile(
        "(?<KEYWORD>\\b(?:int|double)\\b)|" +
        "(?<IDENTIFIER>\\b[a-zA-Z_]\\w*\\b)|" +
        "(?<LITERAL>\\b\\d+(?:\\.\\d*)?\\b)|" +
        "(?<OPERATOR>[=;+;-;/;%;*;])|" +
        "(?<WHITESPACE>\\s+)"
    );

    public static void main(String[] args) {
        List<Token> tokens = tokenize(INPUT);
        for (Token token : tokens) {
            System.out.println(token);
        }
    }

    private static List<Token> tokenize(String input) {
        List<Token> tokens = new ArrayList<>();
        Matcher matcher = REGEX_PATTERN.matcher(input);
        int lastEnd = 0;

        while (matcher.find()) {
            if (matcher.start() != lastEnd) {
                throw new IllegalStateException("Unexpected character(s) found: " + input.substring(lastEnd, matcher.start()));
            }

            String match = matcher.group();
            TokenType tokenType = getTokenType(matcher);
            tokens.add(new Token(tokenType, match));
            lastEnd = matcher.end();
        }

        if (lastEnd != input.length()) {
            throw new IllegalStateException("Unexpected character(s) found: " + input.substring(lastEnd));
        }

        return tokens;
    }

    private static TokenType getTokenType(Matcher matcher) {
        if (matcher.group("KEYWORD") != null) {
            return TokenType.KEYWORD;
        } else if (matcher.group("IDENTIFIER") != null) {
            return TokenType.IDENTIFIER;
        } else if (matcher.group("LITERAL") != null) {
            return TokenType.LITERAL;
        } else if (matcher.group("OPERATOR") != null) {
            return TokenType.OPERATOR;
        } else if (matcher.group("WHITESPACE") != null) {
            return TokenType.WHITESPACE;
        } else {
            throw new IllegalStateException("Unexpected token type");
        }
    }

    private enum TokenType {
        KEYWORD, IDENTIFIER, LITERAL, OPERATOR, WHITESPACE
    }

    private static class Token {
        private final TokenType type;
        private final String value;

        Token(TokenType type, String value) {
            this.type = type;
            this.value = value;
        }

        @Override
        public String toString() {
            return "(" + type + ": '" + value + "')";
        }
    }
}